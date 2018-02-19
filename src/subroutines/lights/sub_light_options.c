/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_light_primary_ray.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:40:31 by nthibaud          #+#    #+#             */
/*   Updated: 2018/02/07 16:06:31 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void 	 	 	fresnel(t_vect ray, t_hit hit, double *refraction, double *kr)
{
	t_refra	ref;

	ref.cosi = ft_clamp(-1, 1, v_dot(ray.dir, hit.normal_dir));
	ref.etai = 1;
	ref.etat = *refraction;
	if (ref.cosi > 0)
		ft_floatswap(&ref.etai, &ref.etat);
	ref.sint = ref.etai / ref.etat * sqrtf(ft_fmax(0.f, 1 - ref.cosi * \
		ref.cosi));
	if (ref.sint >= 1)
		*kr = 1;
	else
	{
		ref.cost = sqrtf(ft_fmax(0.f, 1 - ref.sint * ref.sint));
		ref.cosi = fabsf(ref.cosi);
		ref.rs = ((ref.etat * ref.cosi) - (ref.etai * ref.cost)) / \
		((ref.etat * ref.cosi) + (ref.etai * ref.cost));
		ref.rp = ((ref.etai * ref.cosi) - (ref.etat * ref.cost)) / \
		((ref.etai * ref.cosi) + (ref.etat * ref.cost));
		*kr = (ref.rs * ref.rs + ref.rp * ref.rp) / 2;
	}
}

t_3d_double 	rt_refract(t_vect ray, t_hit hit, double *refraction)
{
	t_refra	ref;

	ref.cosi = ft_clamp(-1, 1, v_dot(ray.dir, hit.normal_dir));
	ref.etai = 1;
	ref.etat = *refraction;
	ref.refranorm = hit.normal_dir;
	if (ref.cosi < 0)
		ref.cosi = -ref.cosi;
	else
	{
		ft_floatswap(&ref.etai, &ref.etat);
		ref.refranorm = v_mult_by_nb(hit.normal_dir, -1);
	}
	ref.eta = ref.etai / ref.etat;
	ref.k = 1 - ref.eta * ref.eta * (1 - ref.cosi * ref.cosi);
	ref.tmpdir = v_mult_by_nb(ray.dir, ref.eta);
	if (ref.k >= 0)
		ref.tmpnorm = v_mult_by_nb(ref.refranorm, ref.eta * ref.cosi - \
			sqrtf(ref.k));
	return (ref.k < 0 ? (t_3d_double){0,0,0} : v_sum(ref.tmpdir, ref.tmpnorm));
}

t_3d_double		sub_reflection(t_fullmap *map, t_hit hit, t_vect *ray, \
	int depth)
{
	double		reflect;
	t_3d_double	tmp;

	if (hit.obj->type == SPHERE || hit.obj->type == CYLINDER \
		 || hit.obj->type == CONE)
		map->coef *= hit.obj->reflection;
	ray->pos = hit.pos;
	reflect = 2 * v_dot(ray->dir, hit.normal_dir);
	tmp = v_mult_by_nb(hit.normal_dir, reflect);
	ray->dir = v_sub_a_by_b(ray->dir, tmp);
	v_normalize(&ray->dir);
	ray->ndir = ray->dir;
	return(raytrace_loop(map, *ray, depth + 1));
}

t_3d_double		sub_refraction(t_fullmap *map, t_hit hit, t_vect *ray, int depth)
{
	t_frafle	ref;

	fresnel(*ray, hit, &hit.obj->refraction, &ref.kr);
	ref.outside = (v_dot(ray->dir, hit.normal_dir) < 0 ? 1 : 0);
	ref.bias = v_mult_by_nb(hit.normal_dir, BIAS);
	if (ref.kr < 1)
	{
		ref.refraray.dir = rt_refract(*ray, hit, &hit.obj->refraction);
		v_normalize(&ref.refraray.dir);
		ref.refleray.ndir = ref.refleray.dir;
		ref.refraray.pos = ref.outside == 1 ? v_sub_a_by_b(hit.pos, ref.bias) \
		: v_sum(hit.pos, ref.bias);
		ref.refracolor = raytrace_loop(map, ref.refraray, depth + 1);
		ref.refracolor = v_mult_by_nb(ref.refracolor, 1 - ref.kr);
		ref.refracolor = v_mult_by_nb(ref.refracolor, hit.obj->refracoef);
	}
	ref.refleray.pos = hit.pos;
	ref.reflect = 2 * v_dot(ray->dir, hit.normal_dir);
	ref.tmp = v_mult_by_nb(hit.normal_dir, ref.reflect);
	ref.refleray.dir = v_sub_a_by_b(ray->dir, ref.tmp);
	v_normalize(&ref.refleray.dir);
	ref.refleray.ndir = ref.refleray.dir;
	ref.reflecolor = raytrace_loop(map, ref.refleray, depth + 1);
	ref.reflecolor = v_mult_by_nb(ref.reflecolor, ref.kr);
	ref.reflecolor = v_mult_by_nb(ref.reflecolor, hit.obj->reflection);
	return(v_sum(ref.reflecolor, ref.refracolor));
}

void		 	sub_perturb_normal(t_hit *hit, int *perlinmp)
{
	t_3d_double	noisecoef;
	double 		temp;

	noisecoef.x = (float)(noise3(hit->pos.x, hit->pos.y, hit->pos.z, perlinmp));
	noisecoef.y = (float)(noise3(hit->pos.y, hit->pos.z, hit->pos.x, perlinmp));
	noisecoef.z = (float)(noise3(hit->pos.z, hit->pos.x, hit->pos.y, perlinmp));
	hit->normal_dir.x = (1.0f - hit->obj->bump) * hit->normal_dir.x +\
	 hit->obj->bump * noisecoef.x;
	hit->normal_dir.y = (1.0f - hit->obj->bump) * hit->normal_dir.y +\
	 hit->obj->bump * noisecoef.y;
	hit->normal_dir.z = (1.0f - hit->obj->bump) * hit->normal_dir.z +\
	 hit->obj->bump * noisecoef.z;
	temp = v_dot(hit->normal_dir, hit->normal_dir);
	if (temp != 0.0f)
	{
		temp = 1 / sqrtf(temp);
		hit->normal_dir = v_mult_by_nb(hit->normal_dir, temp);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_light_primary_ray.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:40:31 by nthibaud          #+#    #+#             */
/*   Updated: 2017/12/07 14:08:13 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	shadow_ray(t_fullmap *map, t_light light)
{
	t_hit	hit;
	t_vect	ray;

	ray.dir = light.ray.dir;
	ray.ndir = v_norm(ray.dir);
	ray.pos = v_sum(light.ray.pos, v_mult_by_nb(ray.ndir, BIAS));
	hit = sub_inter_objects(map, ray);
	if (hit.is_hit == 1)
	{
		if (hit.dist < v_len(v_sub_a_by_b(light.pos, ray.pos)))
				return (1);
	}
	return (0);
}

static t_3d_double	light_color_2(t_fullmap *map, t_3d_double intensity, t_hit hit, t_light light, t_vect *ray)
{
	t_3d_double	c_light;
	t_3d_double	c_obj;
	t_3d_double	color;
	double	dot;

	c_light = v_mult_by_v(v_mult_by_nb(light.color,
			(double)(hit.obj->albedo / PI)), intensity);
	c_obj = v_mult_by_v(v_mult_by_nb(hit.obj->rgb_color,
			(double)(hit.obj->albedo / PI)), intensity);
	color = v_sum(c_light, c_obj);
	dot = v_dot(hit.normal_dir, light.ray.dir);
	if (hit.obj->type == PLANE && (v_dot(v_mult_by_nb(hit.normal_dir, -1), ray->dir) < 0))
			dot = v_dot(v_mult_by_nb(hit.normal_dir, -1), light.ray.dir);
	if (dot < 0)
		dot = 0;
	color = v_mult_by_nb(color, dot);
	return (color);
}

static t_3d_double	light_color_1(t_fullmap *map, t_hit hit, t_light light, t_vect *ray)
{
	t_3d_double	color;
	t_3d_double	intensity;
	double	l_ray_len;

	color = (t_3d_double){0,0,0};
	light.ray.pos = hit.pos;
	light.ray.dir = v_sub_a_by_b(light.pos, hit.pos);
	l_ray_len = v_len(light.ray.dir);
	light.ray.ndir = v_norm(light.ray.dir);
	if (shadow_ray(map, light) != 0)
		return (color);
	intensity = v_div_by_nb(v_mult_by_nb(hit.obj->rgb_color, light.intensity), 4.0 * PI * l_ray_len);
	color = light_color_2(map, intensity, hit, light, ray);
	return (color);
}

void 	fresnel(t_vect ray, t_hit hit, double *refraction, float *kr)
{
	float cosi = ft_clamp(-1, 1, v_dot(ray.dir, hit.normal_dir));
	float etai = 1;
	float etat = *refraction;
	float tmp;
	if (cosi > 0)
	{
		tmp = etai;
		etai = etat;
		etat = tmp;
	}
	float sint = etai / etat * sqrtf(ft_fmax(0.f, 1 - cosi * cosi));
	if (sint >= 1)
	{
		*kr = 1;
	}
	else
	{
		float cost = sqrtf(ft_fmax(0.f, 1 - sint * sint));
		cosi = fabsf(cosi);
		float Rs = ((etat * cosi) - (etai * cost)) / ((etat * cosi) + (etai * cost));
		float Rp = ((etai * cosi) - (etat * cost)) / ((etai * cosi) + (etat * cost));
		*kr = (Rs * Rs + Rp * Rp) / 2;
	}
}

t_3d_double 	rt_refract(t_vect ray, t_hit hit, double *refraction)
{
	float cosa = ft_clamp(-1, 1, v_dot(ray.dir, hit.normal_dir));
	float tmp;
	float etai = 1;
	float etat = *refraction;
	t_3d_double tmpdir;
	t_3d_double tmpnorm;
	t_3d_double refranorm;
	t_3d_double empty;
	empty.x = 0;
	empty.y = 0;
	empty.z = 0;
	refranorm.x = hit.normal_dir.x;
	refranorm.y = hit.normal_dir.y;
	refranorm.z = hit.normal_dir.z;
	if (cosa < 0)
		cosa = -cosa;
	else
	{
		tmp = etai;
		etai = etat;
		etat = tmp;
		refranorm.x = -hit.normal_dir.x;
		refranorm.y = -hit.normal_dir.y;
		refranorm.z = -hit.normal_dir.z;
	}
	float eta = etai / etat;
	float k = 1 - eta * eta * (1 - cosa * cosa);
	tmpdir = v_mult_by_nb(ray.dir, eta);
	if (k >= 0)
		tmpnorm = v_mult_by_nb(refranorm, eta * cosa - sqrtf(k));
	return (k < 0 ? empty : v_sum(tmpdir, tmpnorm));
}

t_3d_double	sub_light_primary_ray(t_fullmap *map, t_hit hit, t_vect *ray, int depth)
{
	t_3d_double	color;
	t_light		light;
	int			i;
	double	reflect;
	t_3d_double	tmp;
	t_vect		refleray;
	t_vect		refraray;
	t_3d_double	refracolor;
	t_3d_double	reflecolor;
	float		kr;

	static t_texture_ft_tab funct_tab =
	{
		sub_texture_sphere
	};

	i = 0;
	color = (t_3d_double){0,0,0};
	if (hit.obj->texture)
		hit.obj->rgb_color = ft_int_to_double_3d(funct_tab[hit.obj->type - 1](hit));
	else
		hit.obj->rgb_color = ft_int_to_double_3d(hit.obj->color);
	while (i < map->light_c)
	{
		light.pos = map->light[i].pos;
		light.intensity = map->light[i].intensity;
		light.color = map->light[i].color;
		color = v_sum(color, light_color_1(map, hit, light, ray));
		i++;
	}
	if (hit.obj->material == REFLECTIVE)
	{
		if (hit.obj->type == SPHERE || hit.obj->type == CYLINDER \
			 || hit.obj->type == CONE)
			map->coef *= hit.obj->reflection;
		ray->pos = hit.pos;
		reflect = 2 * v_dot(ray->dir, hit.normal_dir);
		tmp = v_mult_by_nb(hit.normal_dir, reflect);
		ray->dir = v_sub_a_by_b(ray->dir, tmp);
		v_normalize(&ray->dir);
		ray->ndir = ray->dir;
		reflecolor = raytrace_loop(map, *ray, depth + 1);
		color = v_sum(color, reflecolor);
		color = v_mult_by_nb(color, map->coef);
	}
	else if (hit.obj->material == REFRAFLECTIVE)
	{
		fresnel(*ray, hit, &hit.obj->refraction, &kr);
		int outside = (v_dot(ray->dir, hit.normal_dir) < 0 ? 1 : 0);
		t_3d_double bias = v_mult_by_nb(hit.normal_dir, BIAS);
		if (kr < 1)
		{
			refraray.dir = rt_refract(*ray, hit, &hit.obj->refraction);
			v_normalize(&refraray.dir);
			refleray.ndir = refleray.dir;
			refraray.pos = outside == 1 ? v_sub_a_by_b(hit.pos, bias) : v_sum(hit.pos, bias);
			refracolor = raytrace_loop(map, refraray, depth + 1);
			refracolor = v_mult_by_nb(refracolor, 1 - kr);
			refracolor = v_mult_by_nb(refracolor, hit.obj->refracoef);
		}
		refleray.pos = hit.pos;
		reflect = 2 * v_dot(ray->dir, hit.normal_dir);
		tmp = v_mult_by_nb(hit.normal_dir, reflect);
		refleray.dir = v_sub_a_by_b(ray->dir, tmp);
		v_normalize(&refleray.dir);
		refleray.ndir = refleray.dir;
		reflecolor = raytrace_loop(map, refleray, depth + 1);
		reflecolor = v_mult_by_nb(reflecolor, kr);
		reflecolor = v_mult_by_nb(reflecolor, hit.obj->reflection);
		color = v_sum(color, v_sum(reflecolor, refracolor));
	}
	return (color);
}

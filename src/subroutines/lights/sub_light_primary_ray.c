/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_light_primary_ray.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:40:31 by nthibaud          #+#    #+#             */
/*   Updated: 2018/02/02 16:13:46 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	shadow_ray(t_fullmap *map, t_light light)
{
	t_hit	hit;
	t_vect	ray;

	map->shadowcoef = 0;
	ray.dir = light.ray.dir;
	ray.ndir = v_norm(ray.dir);
	ray.pos = v_sum(light.ray.pos, v_mult_by_nb(ray.ndir, BIAS));
	hit = sub_inter_objects(map, ray);
	if (hit.is_hit == 1 && hit.obj->material == REFRAFLECTIVE)
		fresnel(ray, hit, &hit.obj->refraction, &map->shadowcoef);
	map->shadowcoef = 1 - map->shadowcoef;
	if (hit.is_hit == 0)
		map->shadowcoef = 0;
	else if (hit.dist >= v_len(v_sub_a_by_b(light.pos, ray.pos)))
		map->shadowcoef = 0;
}

void 	fresnel(t_vect ray, t_hit hit, double *refraction, double *kr)
{
	t_refra	ref;

	ref.cosi = ft_clamp(-1, 1, v_dot(ray.dir, hit.normal_dir));
	ref.etai = 1;
	ref.etat = *refraction;
	if (ref.cosi > 0)
		ft_floatswap(&ref.etai, &ref.etat);
	ref.sint = ref.etai / ref.etat * sqrtf(ft_fmax(0.f, 1 - ref.cosi * ref.cosi));
	if (ref.sint >= 1)
		*kr = 1;
	else
	{
		ref.cost = sqrtf(ft_fmax(0.f, 1 - ref.sint * ref.sint));
		ref.cosi = fabsf(ref.cosi);
		ref.rs = ((ref.etat * ref.cosi) - (ref.etai * ref.cost)) / ((ref.etat * ref.cosi) + (ref.etai * ref.cost));
		ref.rp = ((ref.etai * ref.cosi) - (ref.etat * ref.cost)) / ((ref.etai * ref.cosi) + (ref.etat * ref.cost));
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
		ref.tmpnorm = v_mult_by_nb(ref.refranorm, ref.eta * ref.cosi - sqrtf(ref.k));
	return (ref.k < 0 ? (t_3d_double){0,0,0} : v_sum(ref.tmpdir, ref.tmpnorm));
}

t_3d_double		sub_reflection(t_fullmap *map, t_hit hit, t_vect *ray, int depth)
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
		ref.refraray.pos = ref.outside == 1 ? v_sub_a_by_b(hit.pos, ref.bias) : v_sum(hit.pos, ref.bias);
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

void		sub_perturb_normal(t_hit *hit, int *perlin_map)
{
	t_3d_double	noisecoef;
	double 		temp;

	noisecoef.x = (float)(noise3(hit->pos.x, hit->pos.y, hit->pos.z, perlin_map));
	noisecoef.y = (float)(noise3(hit->pos.y, hit->pos.z, hit->pos.x, perlin_map));
	noisecoef.z = (float)(noise3(hit->pos.z, hit->pos.x, hit->pos.y, perlin_map));
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

static t_3d_double	specular_light(t_fullmap *map, t_hit hit, t_light light, t_vect *ray)
{
	t_3d_double	color;
	t_3d_double	spec_color;
	t_3d_double	half_vector;
	double		dot;

	color = (t_3d_double){0,0,0};
	spec_color = v_mult_by_nb(v_mult_by_nb(light.color, light.intensity), hit.obj->spec_power);
	half_vector = v_norm(v_sum(v_norm(v_sub_a_by_b(light.pos, hit.pos)), v_mult_by_nb(ray->dir, -1)));
	dot = v_dot(hit.normal_dir, half_vector);
	if (dot < 0.0)
		dot = 0.0;
	color = v_mult_by_nb(spec_color, pow(dot, hit.obj->spec_size));
	color = v_mult_by_nb(color, 1 - map->shadowcoef);
	return (color);
}
static t_3d_double	diffuse_light_2(t_fullmap *map, t_3d_double intensity, t_hit hit, t_light light, t_vect *ray)
{
	t_3d_double	c_light;
	t_3d_double	c_obj;
	t_3d_double	color;
	double	dot;

	c_light = v_mult_by_v(v_mult_by_nb(light.color,
			(double)(hit.obj->albedo / PI)), intensity);
	c_obj = v_mult_by_v(v_mult_by_nb(hit.obj->rgb_color,
			(double)(hit.obj->albedo / PI)), intensity);
	c_obj = v_mult_by_nb(c_obj, map->color_saturation);
	color = v_sum(c_light, c_obj);
	dot = v_dot(hit.normal_dir, light.ray.dir);
	if (hit.obj->type == PLANE && (v_dot(v_mult_by_nb(hit.normal_dir, -1), ray->dir) < 0))
			dot = v_dot(v_mult_by_nb(hit.normal_dir, -1), light.ray.dir);
	if (dot < 0)
		dot = 0;
	color = v_mult_by_nb(color, dot);
	color = v_mult_by_nb(color, 1 - map->shadowcoef);
	color = v_sum(color, v_mult_by_nb(c_obj, map->amb_coef));
	return (color);
}

static t_3d_double	diffuse_light(t_fullmap *map, t_hit hit, t_light light, t_vect *ray)
{
	t_3d_double	color;
	t_3d_double	intensity;
	double	l_ray_len;

	color = (t_3d_double){0,0,0};
	light.ray.pos = hit.pos;
	light.ray.dir = v_sub_a_by_b(light.pos, hit.pos);
	l_ray_len = v_len(light.ray.dir);
	light.ray.ndir = v_norm(light.ray.dir);
	shadow_ray(map, light);
	intensity = v_div_by_nb(v_mult_by_nb(light.color, light.intensity), 4.0 * PI * l_ray_len);
	color = diffuse_light_2(map, intensity, hit, light, ray);
	return (color);
}

t_3d_double	sub_light_primary_ray(t_fullmap *map, t_hit hit, t_vect *ray, int depth)
{
	t_3d_double	color;
	t_3d_double spe_color;
	t_light		light;
	int			i;
	static t_texture_ft_tab funct_tab =
	{
		sub_texture_sphere,
		sub_texture_cone_cyl,
		sub_texture_cone_cyl
	};
	i = 0;
	color = (t_3d_double){0,0,0};
	spe_color = (t_3d_double){0,0,0};
	if (hit.obj->texture)
		hit.obj->rgb_color = ft_int_to_double_3d(funct_tab[hit.obj->type - 1](hit));
	else
		hit.obj->rgb_color = ft_int_to_double_3d(hit.obj->color);
	sub_texturechange(hit, map);
	if (hit.obj->bump > 0)
		sub_perturb_normal(&hit, map->perlin_tab);
	while (i < map->light_c)
	{
		light.pos = map->light[i].pos;
		light.intensity = map->light[i].intensity;
		light.color = map->light[i].color;
		color = v_sum(color, diffuse_light(map, hit, light, ray));
		spe_color = v_sum(spe_color, specular_light(map, hit, light, ray));
		i++;
	}
	color = v_sum(color, spe_color);
	if (hit.obj->material == REFLECTIVE)
	{
		color = v_sum(color, sub_reflection(map, hit, ray, depth));
		color = v_mult_by_nb(color, map->coef);
	}
	else if (hit.obj->material == REFRAFLECTIVE)
		color = v_sum(color, sub_refraction(map, hit, ray, depth));
	return (color);
}

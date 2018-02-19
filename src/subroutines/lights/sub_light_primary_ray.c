/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_light_primary_ray.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:40:31 by nthibaud          #+#    #+#             */
/*   Updated: 2018/02/19 21:18:15 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void				shadow_ray(t_fullmap *map, t_light light)
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

static t_3d_double		specular_light(t_fullmap *map, t_hit hit,
							t_light light, t_vect *ray)
{
	t_3d_double	color;
	t_3d_double	spec_color;
	t_3d_double	half_vector;
	double		dot;

	color = (t_3d_double){0, 0, 0};
	spec_color = v_mult_by_nb(v_mult_by_nb(light.color, light.intensity),
		hit.obj->spec_power);
	half_vector = v_norm(v_sum(v_norm(v_sub_a_by_b(light.pos, hit.pos)),
		v_mult_by_nb(ray->dir, -1)));
	dot = v_dot(hit.normal_dir, half_vector);
	if (dot < 0.0)
		dot = 0.0;
	color = v_mult_by_nb(spec_color, pow(dot, hit.obj->spec_size));
	color = v_mult_by_nb(color, 1 - map->shadowcoef);
	return (color);
}

static t_3d_double		diffuse_light_2(t_fullmap *map, t_3d_double intensity,
							t_hit hit, t_light light, t_vect *ray)
{
	t_3d_double	c_light;
	t_3d_double	c_obj;
	t_3d_double	color;
	double		dot;

	c_light = v_mult_by_v(v_mult_by_nb(light.color,
			(double)(hit.obj->albedo / PI)), intensity);
	c_obj = v_mult_by_v(v_mult_by_nb(hit.rgb_color,
			(double)(hit.obj->albedo / PI)), intensity);
	c_obj = v_mult_by_nb(c_obj, map->color_saturation);
	color = v_sum(c_light, c_obj);
	dot = v_dot(hit.normal_dir, light.ray.dir);
	if (hit.obj->type == PLANE && (v_dot(v_mult_by_nb(hit.normal_dir, -1),
		ray->dir) < 0))
		dot = v_dot(v_mult_by_nb(hit.normal_dir, -1), light.ray.dir);
	if (dot < 0)
		dot = 0;
	color = v_mult_by_nb(color, dot);
	color = v_mult_by_nb(color, 1 - map->shadowcoef);
	color = v_sum(color, v_mult_by_nb(c_obj, map->amb_coef));
	return (color);
}

static t_3d_double		diffuse_light(t_fullmap *map, t_hit hit, t_light light,
								t_vect *ray)
{
	t_3d_double	color;
	t_3d_double	intensity;
	double		l_ray_len;

	color = (t_3d_double){0, 0, 0};
	light.ray.pos = hit.pos;
	light.ray.dir = v_sub_a_by_b(light.pos, hit.pos);
	l_ray_len = v_len(light.ray.dir);
	light.ray.ndir = v_norm(light.ray.dir);
	shadow_ray(map, light);
	intensity = v_div_by_nb(v_mult_by_nb(light.color, light.intensity),
		4.0 * PI * l_ray_len);
	color = diffuse_light_2(map, intensity, hit, light, ray);
	return (color);
}

t_3d_double				sub_light_primary_ray(t_fullmap *map, t_hit hit,
							t_vect *ray, int depth)
{
	t_3d_double				color;
	t_3d_double				spe_color;
	t_light					light;
	int						i;
	static t_texture_ft_tab	funct_tab =

	{
		sub_texture_sphere,
		sub_texture_cone_cyl,
		sub_texture_cone_cyl
	};
	i = 0;
	color = (t_3d_double){0, 0, 0};
	spe_color = (t_3d_double){0, 0, 0};
	if (hit.obj->texture)
		hit.rgb_color = ft_int_to_double_3d(funct_tab[hit.obj->type - 1](hit));
	else
		hit.rgb_color = ft_int_to_double_3d(hit.obj->color);
	hit.rgb_color = sub_texture_change(hit, map);
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
		color = v_sum(color, sub_refr(map, hit, ray, depth));
	return (color);
}

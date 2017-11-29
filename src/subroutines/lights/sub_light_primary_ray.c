/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_light_primary_ray.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:40:31 by nthibaud          #+#    #+#             */
/*   Updated: 2017/11/29 12:49:13 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_ui	double_3d_to_int(t_3d_double color)
{
	t_ui new_color;

	if (color.x > 255)
		color.x = 255;
	else if (color.x < 0)
		color.x = 0;
	if (color.y > 255)
		color.y = 255;
	else if (color.y < 0)
		color.y = 0;
	if (color.z > 255)
		color.z = 255;
	else if (color.z < 0)
		color.z = 0;
	new_color = (t_ui)color.x * 0x010000 + (t_ui)color.y * 0x000100 + (t_ui)color.z;
	return (new_color);
}

static int	shadow_ray(t_fullmap *map, t_light light)
{
	t_hit	hit;
	t_vect	ray;

	ray.dir = v_mult_by_nb(light.ray.dir, -1);
	ray.ndir = v_norm(ray.dir);
	ray.pos = v_sum(light.ray.pos, v_mult_by_nb(ray.ndir, light.bias));
	hit = sub_inter_objects(map, ray);
	if (hit.is_hit == 1)
	{
		if (hit.dist < v_len(v_sub_a_by_b(light.ray.pos, light.pos)))
				return (1);
	}
	return (0);
}

static t_3d_double	light_color_2(t_fullmap *map, t_3d_double intensity, t_hit hit, t_light light)
{
	t_3d_double	inv_dir;
	t_3d_double	c_light;
	t_3d_double	c_obj;
	t_3d_double	color;
	double	dot;

	inv_dir = v_mult_by_nb(light.ray.dir, -1);
	c_light = v_mult_by_v(v_mult_by_nb(light.color,
			(double)(hit.obj->albedo / PI)), intensity);
	c_obj = v_mult_by_v(v_mult_by_nb(hit.obj->rgb_color,
			(double)(hit.obj->albedo / PI)), intensity);
	color = v_sum(c_light, c_obj);
	dot = v_dot(hit.normal_dir, inv_dir);
	if (dot < 0)
		dot = 0;
	color = v_mult_by_nb(color, dot);
	return (color);
}

static t_3d_double	light_color_1(t_fullmap *map, t_hit hit, t_light light)
{
	t_3d_double	color;
	t_3d_double	intensity;
	double	l_ray_len;

	light.ray.pos = hit.pos;
	light.ray.dir = v_sub_a_by_b(hit.pos, light.pos);
	l_ray_len = v_len(light.ray.dir);
	light.ray.dir = v_norm(light.ray.dir);
	if (shadow_ray(map, light) != 0)
		return (color);
	intensity = v_div_by_nb(v_mult_by_nb(hit.obj->rgb_color, light.intensity), 4.0 * PI * l_ray_len);
	color = light_color_2(map, intensity, hit, light);
	return (color);
}

static t_3d_double	int_to_3d_double(t_ui color)
{
	t_3d_double new_color;

	new_color.x = (double)((color & 0xFF0000) >> 16);
	new_color.y = (double)((color & 0x00FF00) >> 8);
	new_color.z = (double)(color & 0x0000FF);
	return (new_color);
}

t_ui	sub_light_primary_ray(t_fullmap *map, t_hit hit)
{
	t_3d_double	color;
	t_light		light;
	int			i;

	i = 0;
	color = (t_3d_double){0,0,0};
	hit.obj->rgb_color = int_to_3d_double(hit.obj->color);
//	hit.obj->rgb_color = (t_3d_double){255,0,0};
	hit.obj->albedo = 0.18;
	// PROB
	light.intensity = 1.5;
	//PROB
	light.bias = 0.00001;
	light.color = (t_3d_double){255,255,255};
	while (i < map->light_c)
	{
		light.pos = map->light[i].pos;
	//	light.intensity = map->light[i].intensity;
		color = v_sum(color, light_color_1(map, hit, light));
	printf("i %d ", i);
	display_3d_double("color", color);
		i++;
	}
	return (double_3d_to_int(color));
}

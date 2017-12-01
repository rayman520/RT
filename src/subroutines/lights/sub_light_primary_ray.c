/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_light_primary_ray.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:40:31 by nthibaud          #+#    #+#             */
/*   Updated: 2017/12/01 16:52:47 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	shadow_ray(t_fullmap *map, t_light light)
{
	t_hit	hit;
	t_vect	ray;

	ray.dir = v_mult_by_nb(light.ray.dir, -1);
//	ray.dir = light.ray.dir;
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

	color = (t_3d_double){0,0,0};
	light.ray.pos = hit.pos;
	light.ray.dir = v_sub_a_by_b(hit.pos, light.pos);
	l_ray_len = v_len(light.ray.dir);
	light.ray.ndir = v_norm(light.ray.dir);
	if (shadow_ray(map, light) != 0)
		return (color);
	intensity = v_div_by_nb(v_mult_by_nb(hit.obj->rgb_color, light.intensity), 4.0 * PI * l_ray_len);
	color = light_color_2(map, intensity, hit, light);
	return (color);
}


t_ui	sub_light_primary_ray(t_fullmap *map, t_hit hit)
{
	t_3d_double	color;
	t_light		light;
	int			i;
	static t_texture_ft_tab funct_tab =
	{
		sub_texture_sphere
	};

	i = 0;
	color = (t_3d_double){0,0,0};
	// PARSER 
	if (hit.obj->texture)
		hit.obj->rgb_color = ft_int_to_double_3d(funct_tab[hit.obj->type - 1](hit));
	else
		hit.obj->rgb_color = ft_int_to_double_3d(hit.obj->color);
	hit.obj->albedo = 0.18;
	light.intensity = 2;
	light.bias = 0.00001;
	light.color = (t_3d_double){255,255,255};
	// PARSER

	while (i < map->light_c)
	{
		light.pos = map->light[i].pos;
	// PARSER
	//	light.intensity = map->light[i].intensity;
	// PARSER
		color = v_sum(color, light_color_1(map, hit, light));
		i++;
	}
	return (ft_double_3d_to_int(color));
}

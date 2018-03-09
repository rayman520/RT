/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_light_primary_ray.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:40:31 by nthibaud          #+#    #+#             */
/*   Updated: 2018/03/05 13:30:06 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void					texture_and_bump(t_fullmap *map, t_hit *hit)
{
	static t_texture_ft_tab	funct_tab =

	{
		sub_texture_sphere,
		sub_texture_cone_cyl,
		sub_texture_cone_cyl
	};
	if (hit->obj->texture && (hit->obj->type == SPHERE ||
				hit->obj->type == CONE || hit->obj->type == CYLINDER))
	{
		hit->rgb_color =
			ft_int_to_double_3d(funct_tab[hit->obj->type - 1](*hit));
	}
	else
		hit->rgb_color = ft_int_to_double_3d(hit->obj->color);
	hit->rgb_color = sub_texture_change(*hit, map);
	if (hit->obj->bump > 0)
		sub_perturb_normal(hit, map->perlin_tab);
}

t_3d_double				sub_light_primary_ray(t_fullmap *map, t_hit hit,
							t_vect *ray, int depth)
{
	t_3d_double				color;
	t_light					light;

	light = (t_light){NULL_POS, 0, 0, NULL_POS, *ray, 0.0};
	texture_and_bump(map, &hit);
	color = sub_light_compute_color(map, hit, light, ray);
	if (hit.obj->material == REFLECTIVE)
	{
		color = v_sum(color, sub_reflection(map, hit, ray, depth));
		color = v_mult_by_nb(color, map->coef);
	}
	else if (hit.obj->material == REFRAFLECTIVE)
		color = v_sum(color, sub_refr(map, hit, ray, depth));
	return (color);
}

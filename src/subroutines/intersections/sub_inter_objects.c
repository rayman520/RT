/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_inter_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:08:27 by nthibaud          #+#    #+#             */
/*   Updated: 2018/02/20 09:36:40 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	rt_check_minmax(t_3d_double min, t_3d_double max, t_hit *hit)
{
	if (hit->pos.x < min.x || hit->pos.x > max.x)
		hit->is_hit = 0;
	if (hit->pos.y < min.y || hit->pos.y > max.y)
		hit->is_hit = 0;
	if (hit->pos.z < min.z || hit->pos.z > max.z)
		hit->is_hit = 0;
}

t_hit	sub_inter_objects(t_fullmap *map, t_vect ray)
{
	t_hit					hit;
	t_hit					new_hit;
	int						i;
	t_vect					neg_ray;
	static t_isect_fnc_tab	funct_tab =

	{
		sub_inter_sphere,
		sub_inter_cone,
		sub_inter_cylinder,
		sub_inter_plane,
		sub_inter_disk,
		sub_inter_triangle,
		sub_inter_quadrangle,
		sub_inter_pyramid_tbase,
		sub_inter_quadrangle,
	};
	hit = (t_hit){NULL_POS, NULL_POS, NULL_POS, NULL_VECT, NULL, RENDER_DIST,
		RENDER_DIST, 0, (t_3d_double){0, 0, 0}};
	i = -1;
	while (++i < map->obj_c)
	{
		new_hit = funct_tab[map->obj[i].type - 1](&map->obj[i], ray);
		rt_check_minmax(new_hit.obj->min, new_hit.obj->max, &new_hit);
		if (new_hit.is_hit == 1 && new_hit.dist < hit.dist && new_hit.dist > \
			EPSILON)
			hit = new_hit;
	}
	if (hit.is_hit == 1 && hit.obj->type >= 1 && hit.obj->type <= 3 && \
		hit.obj->negative == YES)
	{
		neg_ray = ray;
		neg_ray.pos = hit.pos2;
		hit = sub_inter_objects(map, neg_ray);
	}
	return (hit);
}

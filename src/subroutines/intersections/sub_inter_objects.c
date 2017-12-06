/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_inter_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:08:27 by nthibaud          #+#    #+#             */
/*   Updated: 2017/12/06 11:10:28 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	rt_check_minmax(t_3d_double min, t_3d_double max, t_hit *hit)
{
	min.x = -1000000;
	max.x = 1000000;
	min.y = -1000000;
	max.y = 1000000;
	min.z = -1000000;
	max.z = 1000000;
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
	static t_isect_fnc_tab	funct_tab =
	{
		sub_inter_sphere,
		sub_inter_cone,
		sub_inter_cylinder,
		sub_inter_plane,
		sub_inter_disk
	};

	hit = (t_hit){NULL_POS, NULL_POS, NULL_VECT, NULL, RENDER_DIST, 0};
	i = -1;
	while (++i < map->obj_c)
	{
		new_hit = funct_tab[map->obj[i].type - 1](&map->obj[i], ray);
		rt_check_minmax(new_hit.obj->min, new_hit.obj->max, &new_hit);
		if (new_hit.is_hit == 1 && new_hit.dist < hit.dist && new_hit.dist > EPSILON)
			hit = new_hit;
	}
	return (hit);
}

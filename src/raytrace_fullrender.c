/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_fullrender.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:06:07 by nthibaud          #+#    #+#             */
/*   Updated: 2017/11/29 11:02:23 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ui	raytrace_fullrender(t_fullmap *map, t_vect ray)
{
	t_ui	color;
	t_hit	hit;

	hit = sub_inter_objects(map, ray);
	if (hit.is_hit == 0)
		return (0);
	else if (map->light_c > 0)
		color = sub_light_primary_ray(map, hit);
	return (color);
}

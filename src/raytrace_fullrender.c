/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_fullrender.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:06:07 by nthibaud          #+#    #+#             */
/*   Updated: 2018/01/08 15:49:41 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int ft_shade(int i)
{
	if (i <= 10)
		return(0);
	if (i > 10 && i <= 60)
		return(41);
	if (i > 60 && i <= 254)
		return(150);
	if (i > 254)
		return(255);
	else
		return(1);
}

void		ft_rt_filter(t_fullmap *map, t_3d_double *rescolor)
{
	t_3d_double tmp;

	tmp.x = rescolor->x;
	tmp.y = rescolor->y;
	tmp.z = rescolor->z;
	if (map->filter == INVERTED)
	{
		rescolor->x = (rescolor->x <= 255 ? 255 - rescolor->x : 0);
		rescolor->y = (rescolor->y <= 255 ? 255 - rescolor->y : 0);
		rescolor->z = (rescolor->z <= 255 ? 255 - rescolor->z : 0);
	}
	if (map->filter == GRAYSCALE)
	{
		double gray = rescolor->x * 0.3 + rescolor->y * 0.3 + rescolor->z * 0.11;
		rescolor->x = gray;
		rescolor->y = gray;
		rescolor->z = gray;
	}
	if (map->filter == SEPIA)
	{
		rescolor->x = (tmp.x * 0.393) + (tmp.y * 0.769) + (tmp.z * 0.189);
		rescolor->y = (tmp.x * 0.349) + (tmp.y * 0.686) + (tmp.z * 0.168);
		rescolor->z = (tmp.x * 0.272) + (tmp.y * 0.534) + (tmp.z * 0.131);
	}
	if (map->filter == CARTOON)
	{
		rescolor->x = ft_shade(rescolor->x);
		rescolor->y = ft_shade(rescolor->y);
		rescolor->z = ft_shade(rescolor->z);
	}
}

t_3d_double	raytrace_loop(t_fullmap *map, t_vect ray, int depth)
{
	t_3d_double	color;
	t_hit		hit;

	color = (t_3d_double){0,0,15};
	if (depth < map->maxdepth && map->coef > 0)
	{
		hit = sub_inter_objects(map, ray);
		if (hit.is_hit == 1 && map->light_c > 0)
			color = sub_light_primary_ray(map, hit, &ray, depth);
	}
	return (color);
}

t_3d_double	raytrace_fullrender(t_fullmap *map, t_vect ray)
{
	t_3d_double	color;

	map->coef = 1;
	color = raytrace_loop(map, ray, 0);
	ft_rt_filter(map, &color);
	return (color);
}

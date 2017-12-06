/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_inter_cube.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:49:37 by nthibaud          #+#    #+#             */
/*   Updated: 2017/12/05 14:40:53 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	cube_check_minmax(t_3d_double min, t_3d_double max, t_hit *hit)
{
	if (hit->pos.x < min.x || hit->pos.x > max.x)
		hit.is_hit = 0;
	if (hit->pos.y < min.y || hit->pos.y > max.y)
		hit.is_hit = 0;
	if (hit->pos.z < min.z || hit->pos.z > max.z)
		hit.is_hit = 0;
}

t_hit	cube_check(t_3d_double min, t_3d_double max, t_hit *hit)
{
	t_hit nexthit;

	nexthit = sub_inter_plane(cube, ray);
	cube_check_minmax(min, max, hit);
	if (nexthit.is_hit == 1 && hit.dist > nexthit.dist)
		hit = nexthit;
	return (hit);
}

t_hit		sub_inter_cube(t_object *cube, t_vect ray)
{
	t_hit hit;

	cube->pos = cube->min;
	cube->dir = (1, 0, 0);
	hit = sub_inter_plane(cube, ray);
	cube_check_minmax(min, max, hit);
	cube->dir = (0, 1, 0);
	hit = cube_check(cube->min, cube->max, hit);
	cube->dir = (0, 0, 1);
	hit = cube_check(cube->min, cube->max, hit);
	cube->pos = cube->max;
	cube->dir = (1, 0, 0);
	hit = cube_check(cube->min, cube->max, hit);
	cube->dir = (0, 1, 0);
	hit = cube_check(cube->min, cube->max, hit);
	cube->dir = (0, 0, 1);
	hit = cube_check(cube->min, cube->max, hit);
	return(hit)
}

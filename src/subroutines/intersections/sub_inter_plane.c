/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_inter_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:49:37 by bvan-dyc          #+#    #+#             */
/*   Updated: 2018/02/19 17:14:42 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_hit		sub_inter_plane(t_object *plane, t_vect ray)
{
	double		denom;
	t_hit		hit;

	ray.ndir = v_norm(ray.dir);
	plane->dir = v_norm(plane->dir);
	denom = ((v_dot(plane->dir, plane->pos) -
			v_dot(plane->dir, ray.pos)) / v_dot(plane->dir, ray.ndir));
	if (denom >= 0)
		hit.is_hit = 1;
	else
		hit.is_hit = 0;
	hit.dist = denom;
	hit.pos = v_sum(ray.pos, v_mult_by_nb(ray.ndir, hit.dist));
	hit.normal_dir = plane->dir;
	v_normalize(&hit.normal_dir);
	hit.obj = plane;
	return (hit);
}

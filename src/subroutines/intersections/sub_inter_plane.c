/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_inter_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:49:37 by nthibaud          #+#    #+#             */
/*   Updated: 2017/11/28 16:52:20 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
double	plane_inter(t_env *e, t_ray ray, t_obj obj)
{
	double	t;
	t_v3d	d;

	obj.n = v_norm(obj.n);
	d = v_sub_a_by_b(obj.c, ray.o.v);
	t = v_dot(d, obj.n);
	if (v_dot(ray.d.nv, obj.n) != 0)
		t = t / v_dot(ray.d.nv, obj.n);
	if (t >= 0)
		return (t);
	else
		return (-1);
}
*/

t_hit		sub_inter_plane(t_object *plane, t_vect ray)
{
	double		denom;
	t_hit		hit;
	t_3d_double	dist;

	plane->dir = (t_3d_double){0,0,1};
	ray.ndir = v_norm(ray.dir);
	denom = ((v_dot(plane->dir, plane->pos) -
			v_dot(plane->dir, ray.pos)) / v_dot(plane->dir, ray.dir));
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

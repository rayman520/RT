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

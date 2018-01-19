/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_inter_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:06:00 by bvan-dyc          #+#    #+#             */
/*   Updated: 2017/12/04 15:55:41 by bvan-dyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_hit		sub_inter_triangle(t_object *triangle, t_vect ray)
{
	t_triter 	m;
	t_hit		hit;

	hit.is_hit = 1;
	ray.ndir = v_norm(ray.dir);
	m.edge1 = v_sub_a_by_b(triangle->pb, triangle->pa);
	m.edge2 = v_sub_a_by_b(triangle->pc, triangle->pa);
	m.vs1 = v_cross(ray.dir, m.edge2);
	m.det = v_dot(m.edge1, m.vs1);
	if (fabs(m.det) < EPSILON)
		hit.is_hit = 0;
	m.invdet = 1 / m.det;
	m.vs2 = v_sub_a_by_b(ray.pos, triangle->pa);
	m.u = v_dot(m.vs2, m.vs1) * m.invdet;
	if (m.u < 0 || m.u > 1)
		hit.is_hit = 0;
	m.vs3 = v_cross(m.vs2, m.edge1);
	m.v = v_dot(ray.dir, m.vs3) * m.invdet;
	if (m.v < 0 || (m.u + m.v) > 1)
		hit.is_hit = 0;
	m.tmp = v_dot(m.edge2, m.vs3) * m.invdet;
	hit.dist = m.tmp;
	hit.pos = v_sum(ray.pos, v_mult_by_nb(ray.ndir, hit.dist));
	hit.normal_dir = v_norm(v_cross(m.edge2, m.edge1));
	hit.obj = triangle;
	return (hit);
}

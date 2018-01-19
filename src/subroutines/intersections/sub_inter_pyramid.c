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

t_hit		sub_inter_pyramid_tbase(t_object *pyramid, t_vect ray)
{
	t_hit 		hit;
	t_hit 		nhit;
	t_object 	*npyramid;

	pyramid->pa = (t_3d_double){0, 0, 0};
	pyramid->pb = (t_3d_double){0, -10, 0};
	pyramid->pc = (t_3d_double){0, 0, 10};
	pyramid->pd = (t_3d_double){-10, 0, 0};
	npyramid = pyramid;
	hit = sub_inter_triangle(npyramid, ray);
	pyramid->pc = pyramid->pd;
	nhit = sub_inter_triangle(npyramid, ray);
	if (nhit.is_hit == 1 && hit.dist > nhit.dist)
		hit = nhit;
	npyramid = pyramid;
	pyramid->pb = pyramid->pc;
	pyramid->pc = pyramid->pd;
	nhit = sub_inter_triangle(npyramid, ray);
	if (nhit.is_hit == 1 && hit.dist > nhit.dist)
		hit = nhit;
	npyramid = pyramid;
	pyramid->pa = pyramid->pd;
	nhit = sub_inter_triangle(npyramid, ray);
	if (nhit.is_hit == 1 && hit.dist > nhit.dist)
		hit = nhit;
	npyramid = pyramid;
	return (hit);
}
/*
t_hit		sub_inter_pyramid_qbase(t_object *pyramid, t_vect ray)
{
	t_hit 		hit;
	t_hit 		nhit;
	t_object 	*npyramid;
	t_3d_double	pe;

	npyramid = pyramid;
	pe = v_sum(quad->pc, v_sub_a_by_b(quad->pb, quad->pa));
	hit = sub_inter_triangle(npyramid, ray);
	pyramid->pc = pyramid->pd;
	nhit = sub_inter_triangle(npyramid, ray);
	if (nhit.is_hit == 1 && hit.dist > nhit.dist)
		hit = nhit;
	npyramid = pyramid;
	pyramid->pb = pyramid->pd;
	nhit = sub_inter_triangle(npyramid, ray);
	if (nhit.is_hit == 1 && hit.dist > nhit.dist)
		hit = nhit;
	npyramid = pyramid;
	pyramid->pa = pyramid->pd;
	nhit = sub_inter_triangle(npyramid, ray);
	if (nhit.is_hit == 1 && hit.dist > nhit.dist)
		hit = nhit;
	npyramid = pyramid;
	return (hit);
}
*/

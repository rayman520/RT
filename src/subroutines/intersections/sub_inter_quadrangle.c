/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_inter_quadrangle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:06:00 by bvan-dyc          #+#    #+#             */
/*   Updated: 2018/02/19 17:14:51 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_hit		sub_inter_quadrangle(t_object *quad, t_vect ray)
{
	t_hit		hit;
	t_hit		hit2;
	t_object	quadsave;

	if (quad->type == PARALLELOGRAM)
		quad->pd = v_sum(quad->pc, v_sub_a_by_b(quad->pb, quad->pa));
	quadsave = *quad;
	hit = sub_inter_triangle(quad, ray);
	quad->pa = quad->pd;
	quad->pb = quad->pc;
	quad->pc = quadsave.pb;
	hit2 = sub_inter_triangle(quad, ray);
	quad = &quadsave;
	if (hit.is_hit == 0 || hit.dist > hit2.dist)
		return (hit2);
	else
		return (hit);
}

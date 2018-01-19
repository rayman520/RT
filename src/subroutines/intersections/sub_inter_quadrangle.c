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

/*
void		parallel_arrange(t_3d_double *p1, t_3d_double *p2, t_3d_double *p3)
{
	while (p1->y < p2->y || p1->y < p3->y || p2->y < p3->y)
	{
		if (p1->y < p2->y)
			ft_vectorswap(p1, p2);
		if (p1->y < p3->y)
			ft_vectorswap(p1, p3);
		if (p2->y < p3->y)
			ft_vectorswap(p2, p3);
	}
}
	while (p1->z < p2->z || p1->z < p3->z || p2->z < p3->z)
	{
		if (p1->z < p2->z)
			ft_vectorswap(p1, p2);
		if (p1->z < p3->z)
			ft_vectorswap(p1, p3);
		if (p2->z < p3->z)
			ft_vectorswap(p2, p3);
	}
}
*/

t_hit		sub_inter_quadrangle(t_object *quad, t_vect ray)
{
	t_hit 		hit;
	t_hit 		hit2;
	t_object	quadsave;

	if (quad->type == SPHERE) // PARALELLEOGRAM OR CUBE
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

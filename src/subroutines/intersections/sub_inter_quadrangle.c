/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_inter_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:06:00 by nthibaud          #+#    #+#             */
/*   Updated: 2017/12/04 15:55:41 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_hit		sub_inter_quadrangle(t_object *quad, t_vect ray)
{
	t_hit 		hit;
	t_hit 		hit2;
	t_3d_double tmp;

	hit = sub_inter_triangle(quad, ray);
	tmp = quad->pa;
	quad->pa = quad->pd;
	hit2 = sub_inter_triangle(quad, ray);
	quad->pa = tmp;
	if (hit.is_hit == 0 || hit.dist > hit2.dist)
		return (hit2);
	else
		return (hit);
}

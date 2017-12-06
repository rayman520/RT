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
	t_3d_double tmp;

	hit = sub_inter_triangle(quad, ray);
	if (hit.is_hit == 0)
	{
		tmp = quad->pa;
		quad->pa = quad->pd;
		hit = sub_inter_triangle(quad, ray);
		quad->pa = tmp;
	}
	return (hit);
}

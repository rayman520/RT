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

t_hit		sub_inter_piercedcube(t_object *pcube, t_vect ray)
{
	t_hit 		hit;
	t_hit 		nhit;
	double 		c;

	c = cube->max.z - cube->min.z;
	pcube->radius = c / 4;
	pcube->pos.x = cube->min.x + c;
	pcube->pos.y = cube->min.y + c;
	pcube->pos.z = cube->min.z;
	hit = sub_inter_cube(pcube, ray);
	nhit = sub_inter_cylinder(pcube, ray);
	if (hit.is_hit == 1 && nhit.is_hit == 1)
		hit.is_hit = 0;
	return (hit);
}

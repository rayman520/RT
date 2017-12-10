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

t_hit		sub_inter_aabbbox(t_object *cube, t_vect ray)
{
	t_hit 		hit;
	t_hit 		nhit;
	double 		c;
	t_object 	*ncube;

	cube->pb = cube->min;
	cube->pc = cube->max;
	c = cube->pc.z - cube->pb.z;
	cube->pa = cube->pc;
	cube->pa.y -= c;
	cube->pd = v_sum(cube->pc, v_sub_a_by_b(cube->pb, cube->pa));
	ncube = cube;
	hit = sub_inter_parallelogram(ncube, ray);
	cube->pc = cube->pa;
	cube->pc.x -= c;
	nhit = sub_inter_parallelogram(ncube, ray);
	if (nhit.is_hit == 1 && hit.dist > nhit.dist)
		hit = nhit;
	ncube = cube;
	cube->pb = cube->pa;
	cube->pb.x -= c;
	nhit = sub_inter_parallelogram(ncube, ray);
	if (nhit.is_hit == 1 && hit.dist > nhit.dist)
		hit = nhit;
	cube->pa = cube->pc;
	cube->pb = cube->pd;
	cube->pa.x -= c;
	nhit = sub_inter_parallelogram(ncube, ray);
	if (nhit.is_hit == 1 && hit.dist > nhit.dist)
		hit = nhit;
	ncube = cube;
	cube->pa = cube->pb;
	cube->pc = cube->pd;
	cube->pa.x -= c;
	nhit = sub_inter_parallelogram(ncube, ray);
	if (nhit.is_hit == 1 && hit.dist > nhit.dist)
		hit = nhit;
	ncube = cube;
	cube->pa.x -= c;
	cube->pb.x -= c;
	cube->pc.x -= c;
	nhit = sub_inter_parallelogram(ncube, ray);
	if (nhit.is_hit == 1 && hit.dist > nhit.dist)
		hit = nhit;
	return (hit);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_inter_pyramid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:06:00 by bvan-dyc          #+#    #+#             */
/*   Updated: 2018/02/19 17:14:44 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_hit		sub_inter_pyramid_tbase(t_object *pyramid, t_vect ray)
{
	t_hit		hit;
	t_hit		nhit;
	t_object	*npyramid;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_inter_hyperboloid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:06:00 by bvan-dyc          #+#    #+#             */
/*   Updated: 2018/02/19 17:25:06 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		sub_norm_hyperboloid(t_object *hyper, t_hit *hit, t_vect ray)
{
	t_3d_double		dist;

	hit->pos = v_sum(ray.pos, v_mult_by_nb(ray.ndir, hit->dist));
	hit->pos2 = v_sum(ray.pos, v_mult_by_nb(ray.ndir, hit->dist2));
	hit->pos = v_sum(ray.pos, v_mult_by_nb(ray.ndir, 0.1));
	hit->normal_dir.x = hit->pos.x;
	hit->normal_dir.y = -hit->pos.y;
	hit->normal_dir.z = hit->pos.z;
	v_normalize(&hit->normal_dir);
	hit->obj = hyper;
}

t_hit		sub_inter_hyperboloid(t_object *hyper, t_vect ray)
{
	t_hit			hit;
	t_inter			inter;

	ray.ndir = v_norm(ray.dir);
	hit.is_hit = 0;
	inter.dist = v_sub_a_by_b(ray.pos, hyper->pos);
	inter.norm = v_norm(hyper->dir);
	inter.a = ray.dir.x * ray.dir.x - ray.dir.y * ray.dir.y + ray.dir.z *
		ray.dir.z;
	inter.b = 2 * (ray.pos.x * ray.dir.x - ray.pos.y * ray.dir.y + ray.pos.z *
		ray.dir.z);
	inter.c = ray.pos.x * ray.pos.x - ray.pos.y * ray.pos.y + ray.pos.z *
		ray.pos.z - hyper->radius;
	inter.discr = inter.b * inter.b - 4 * inter.a * inter.c;
	hit.is_hit = (inter.discr < 0) ? 0 : 1;
	inter.t0 = (-inter.b + sqrtf(inter.discr)) / (2 * inter.a);
	inter.t1 = (-inter.b - sqrtf(inter.discr)) / (2 * inter.a);
	if (inter.t0 > inter.t1)
		ft_doubleswap(&inter.t0, &inter.t1);
	hit.dist = inter.t0;
	hit.dist = inter.t1;
	sub_norm_hyperboloid(hyper, &hit, ray);
	return (hit);
}

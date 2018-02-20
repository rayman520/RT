/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_inter_hyperboloid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:06:00 by bvan-dyc          #+#    #+#             */
/*   Updated: 2018/02/20 19:54:57 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		sub_norm_hyperboloid(t_object *hyper, t_hit *hit, t_vect ray)
{
	hit->pos = v_sum(ray.pos, v_mult_by_nb(ray.ndir, hit->dist));
	hit->pos2 = v_sum(ray.pos, v_mult_by_nb(ray.ndir, hit->dist2));
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
	inter.a = ray.ndir.x * ray.ndir.x - ray.ndir.y * ray.ndir.y + ray.ndir.z *
		ray.ndir.z;
	inter.b = 2 * (inter.dist.x * ray.ndir.x - inter.dist.y * ray.ndir.y + inter.dist.z *
		ray.ndir.z);
	inter.c = inter.dist.x * inter.dist.x - inter.dist.y * inter.dist.y + inter.dist.z *
		inter.dist.z - hyper->radius;
	inter.discr = inter.b * inter.b - 4 * inter.a * inter.c;
	hit.is_hit = (inter.discr < 0) ? 0 : 1;
	inter.t0 = (-inter.b + sqrtf(inter.discr)) / (2 * inter.a);
	inter.t1 = (-inter.b - sqrtf(inter.discr)) / (2 * inter.a);
	if (inter.t0 > inter.t1)
		ft_doubleswap(&inter.t0, &inter.t1);
	hit.dist = inter.t0;
	hit.dist2 = inter.t1;
	sub_norm_hyperboloid(hyper, &hit, ray);
	return (hit);
}

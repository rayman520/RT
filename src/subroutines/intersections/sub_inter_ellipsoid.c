/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_inter_ellipsoid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:06:00 by bvan-dyc          #+#    #+#             */
/*   Updated: 2018/02/19 17:11:29 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		sub_norm_ellipsoid(t_object *eli, t_hit *hit, t_vect ray)
{
	t_3d_double		dist;

	hit->pos = v_sum(ray.pos, v_mult_by_nb(ray.ndir, hit->dist));
	hit->pos2 = v_sum(ray.pos, v_mult_by_nb(ray.ndir, hit->dist2));
	hit->pos = v_sum(ray.pos, v_mult_by_nb(ray.ndir, 0.1));
	dist = v_sub_a_by_b(ray.pos, eli->pos);
	hit->normal_dir = v_sub_a_by_b(hit->pos, eli->pos);
	hit->normal_dir.x = 2.f * hit->normal_dir.x / (eli->pa.x * eli->pa.x);
	hit->normal_dir.y = 2.f * hit->normal_dir.y / (eli->pa.y * eli->pa.y);
	hit->normal_dir.z = 2.f * hit->normal_dir.z / (eli->pa.z * eli->pa.z);
	v_normalize(&hit->normal_dir);
	hit->obj = eli;
}

t_hit		sub_inter_ellipsoid(t_object *eli, t_vect ray)
{
	t_hit			hit;
	t_inter			inter;

	ray.ndir = v_norm(ray.dir);
	hit.is_hit = 0;
	inter.dist = v_sub_a_by_b(ray.pos, eli->pos);
	inter.norm = v_norm(eli->dir);
	inter.a = ((ray.dir.x * ray.dir.x) / (eli->pa.x * eli->pa.x))
		+ ((ray.dir.y * ray.dir.y) / (eli->pa.y * eli->pa.y))
		+ ((ray.dir.z * ray.dir.z) / (eli->pa.z * eli->pa.z));
	inter.b = ((2.f * inter.dist.x * ray.dir.x) / (eli->pa.x * eli->pa.x))
		+ ((2.f * inter.dist.y * ray.dir.y) / (eli->pa.y * eli->pa.y))
		+ ((2.f * inter.dist.z * ray.dir.z) / (eli->pa.z * eli->pa.z));
	inter.c = ((inter.dist.x * inter.dist.x) / (eli->pa.x * eli->pa.x))
		+ ((inter.dist.y * inter.dist.y) / (eli->pa.y * eli->pa.y))
		+ ((inter.dist.z * inter.dist.z) / (eli->pa.z * eli->pa.z)) - 1.f;
	inter.discr = inter.b * inter.b - 4 * inter.a * inter.c;
	if (inter.discr < 0)
		hit.is_hit = 0;
	else
		hit.is_hit = 1;
	inter.t0 = (-inter.b + sqrtf(inter.discr)) / (2 * inter.a);
	inter.t1 = (-inter.b - sqrtf(inter.discr)) / (2 * inter.a);
	if (inter.t0 > inter.t1)
		ft_doubleswap(&inter.t0, &inter.t1);
	hit.dist = inter.t0;
	hit.dist = inter.t1;
	sub_norm_ellipsoid(eli, &hit, ray);
	return (hit);
}

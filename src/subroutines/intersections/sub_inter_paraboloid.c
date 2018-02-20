/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_inter_paraboloid.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:06:00 by bvan-dyc          #+#    #+#             */
/*   Updated: 2018/02/20 09:37:51 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		sub_norm_paraboloid(t_object *para, t_hit *hit, t_vect ray)
{
	t_3d_double		dist;
	t_3d_double		temp;
	t_3d_double		temp2;

	hit->pos = v_sum(ray.pos, v_mult_by_nb(ray.ndir, hit->dist));
	hit->pos2 = v_sum(ray.pos, v_mult_by_nb(ray.ndir, hit->dist2));
	hit->pos = v_sum(ray.pos, v_mult_by_nb(ray.ndir, 0.1));
	dist = v_sub_a_by_b(ray.pos, para->pos);
	temp = v_mult_by_nb(para->dir, (v_dot(ray.dir, para->dir) * hit->dist +
		v_dot(dist, para->dir) + para->radius));
	temp2 = v_sub_a_by_b(hit->pos, para->pos);
	hit->normal_dir = v_sub_a_by_b(temp2, temp);
	v_normalize(&hit->normal_dir);
	hit->obj = para;
}

t_hit		sub_inter_paraboloid(t_object *para, t_vect ray)
{
	t_hit			hit;
	t_inter			inter;

	ray.ndir = v_norm(ray.dir);
	hit.is_hit = 0;
	inter.dist = v_sub_a_by_b(ray.pos, para->pos);
	inter.norm = v_norm(para->dir);
	inter.a = v_dot(ray.dir, ray.dir) - v_dot(ray.dir, para->dir) *
		v_dot(ray.dir, para->dir);
	inter.b = 2 * (v_dot(ray.dir, ray.pos) - v_dot(ray.dir, para->dir) *
		(v_dot(ray.pos, para->dir) + 2 * para->radius));
	inter.c = v_dot(ray.pos, ray.pos) - v_dot(ray.pos, para->dir) *
		(v_dot(ray.pos, para->dir) + 4 * para->radius);
	inter.discr = inter.b * inter.b - 4 * inter.a * inter.c;
	hit.is_hit = (inter.discr < 0) ? 0 : 1;
	inter.t0 = (-inter.b + sqrtf(inter.discr)) / (2 * inter.a);
	inter.t1 = (-inter.b - sqrtf(inter.discr)) / (2 * inter.a);
	if (inter.t0 > inter.t1)
		ft_doubleswap(&inter.t0, &inter.t1);
	hit.dist = inter.t0;
	hit.dist = inter.t1;
	sub_norm_paraboloid(para, &hit, ray);
	return (hit);
}

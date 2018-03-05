/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_inter_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:06:00 by bvan-dyc          #+#    #+#             */
/*   Updated: 2018/03/05 13:20:40 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		sub_norm_cylinder(t_object *cyl, t_hit *hit, t_vect ray)
{
	t_3d_double		dist;
	t_3d_double		temp;
	t_3d_double		temp2;

	hit->pos = v_sum(ray.pos, v_mult_by_nb(ray.ndir, hit->dist));
	hit->pos2 = v_sum(ray.pos, v_mult_by_nb(ray.ndir, hit->dist2));
	dist = v_sub_a_by_b(ray.pos, cyl->pos);
	temp = v_mult_by_nb(cyl->dir, (v_dot(ray.dir, cyl->dir) * hit->dist
	+ v_dot(dist, cyl->dir)));
	temp2 = v_sub_a_by_b(hit->pos, cyl->pos);
	hit->normal_dir = v_sub_a_by_b(temp2, temp);
	v_normalize(&hit->normal_dir);
	hit->obj = cyl;
}

t_hit		sub_inter_cylinder(t_object *cyl, t_vect ray)
{
	t_hit			hit;
	t_inter			inter;

	hit.is_hit = 1;
	ray.ndir = v_norm(ray.dir);
	inter.dist = v_sub_a_by_b(ray.pos, cyl->pos);
	inter.norm = v_norm(cyl->dir);
	inter.a = v_dot(ray.ndir, ray.ndir) - pow(v_dot(ray.ndir, inter.norm), 2);
	inter.b = 2 * (v_dot(ray.ndir, inter.dist) -
		(v_dot(ray.ndir, inter.norm) * v_dot(inter.dist, inter.norm)));
	inter.c = v_dot(inter.dist, inter.dist) -
		pow(v_dot(inter.dist, inter.norm), 2) - cyl->radius * cyl->radius;
	inter.discr = inter.b * inter.b - 4 * inter.a * inter.c;
	if (inter.discr < 0)
		hit.is_hit = 0;
	inter.t0 = (-inter.b + sqrtf(inter.discr)) / (2 * inter.a);
	inter.t1 = (-inter.b - sqrtf(inter.discr)) / (2 * inter.a);
	if (inter.t0 > inter.t1)
		ft_doubleswap(&inter.t0, &inter.t1);
	hit.dist = inter.t0;
	hit.dist2 = inter.t1;
	sub_norm_cylinder(cyl, &hit, ray);
	return (hit);
}

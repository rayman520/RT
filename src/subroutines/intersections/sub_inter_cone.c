/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_inter_cone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:12:53 by bvan-dyc          #+#    #+#             */
/*   Updated: 2018/02/20 09:34:57 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		sub_norm_cone(t_object *cone, t_hit *hit, t_vect ray)
{
	t_3d_double		dist;
	t_3d_double		temp;
	t_3d_double		temp2;

	hit->pos = v_sum(ray.pos, v_mult_by_nb(ray.ndir, hit->dist));
	hit->pos2 = v_sum(ray.pos, v_mult_by_nb(ray.ndir, hit->dist2));
	dist = v_sub_a_by_b(ray.pos, cone->pos);
	temp = v_mult_by_nb(cone->dir, (v_dot(ray.dir, cone->dir) * hit->dist
	+ v_dot(dist, cone->dir)));
	temp = v_mult_by_nb(temp, (1 + pow(tan(cone->radius), 2)));
	temp2 = v_sub_a_by_b(hit->pos, cone->pos);
	hit->normal_dir = v_sub_a_by_b(temp2, temp);
	v_normalize(&hit->normal_dir);
	hit->obj = cone;
}

t_hit		sub_inter_cone(t_object *cone, t_vect ray)
{
	t_hit			hit;
	t_inter			inter;

	ray.ndir = v_norm(ray.dir);
	hit.is_hit = 0;
	inter.dist = v_sub_a_by_b(ray.pos, cone->pos);
	inter.norm = v_norm(cone->dir);
	inter.a = v_dot(ray.dir, ray.dir) - (1 + pow(tan(cone->radius), 2)) *
		pow(v_dot(ray.dir, inter.norm), 2);
	inter.b = 2 * (v_dot(ray.dir, inter.dist) - (1 + pow(tan(cone->radius), 2))
		* v_dot(ray.dir, inter.norm) * v_dot(inter.dist, inter.norm));
	inter.c = v_dot(inter.dist, inter.dist) - (1 +
		pow(tan(cone->radius), 2)) * pow(v_dot(inter.dist, inter.norm), 2);
	inter.discr = inter.b * inter.b - 4 * inter.a * inter.c;
	hit.is_hit = (inter.discr < 0 ? 0 : 1);
	inter.t0 = (-inter.b + sqrtf(inter.discr)) / (2 * inter.a);
	inter.t1 = (-inter.b - sqrtf(inter.discr)) / (2 * inter.a);
	if (inter.t0 > inter.t1)
		ft_doubleswap(&inter.t0, &inter.t1);
	hit.dist = inter.t0;
	hit.dist2 = inter.t1;
	sub_norm_cone(cone, &hit, ray);
	return (hit);
}

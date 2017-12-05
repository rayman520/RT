/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_inter_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:06:00 by nthibaud          #+#    #+#             */
/*   Updated: 2017/12/05 14:14:03 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double	compute_t(double a, double b, double c, double det)
{
	double	t1;
	double	t2;

	if (det < 0)
		return (-1);
	t1 = (-b + sqrtf(det)) / (2 * a);
	t2 = (-b - sqrtf(det)) / (2 * a);
	if (det == 0)
		return (-b / (2 * a));
	if (t1 < t2)
		return (t1);
	if (t1 < 0 && t2 < 0)
		return (-1);
	return (t2);
}

static double	quadratic_equation(t_vect ray, double r, t_3d_double dc, double *det)
{
	double	a;
	double	b;
	double	c;
	double	t;

	a = v_dot(ray.ndir, ray.ndir);
	b = 2 * v_dot(ray.ndir, dc);
	c = v_dot(dc, dc) - r * r;
	*det = (b * b) - 4 * a * c;
	t = compute_t(a, b, c, *det);
	return (t);
}

t_hit	sub_inter_sphere(t_object *obj, t_vect ray)
{
	double		det;
	double		t;
	double		r;
	t_3d_double	dc;
	t_hit		hit;

	ray.ndir = v_norm(ray.dir);
	r = obj->radius;
	dc = v_sub_a_by_b(ray.pos, obj->pos);
	t = quadratic_equation(ray, r, dc, &det);
	hit.dist = t;
	hit.pos = v_sum(ray.pos, v_mult_by_nb(ray.ndir, t));
	hit.normal_dir = v_norm(v_sub_a_by_b(hit.pos, obj->pos));
	hit.obj = obj;
	if (det < 0)
		hit.is_hit = 0;
	else
		hit.is_hit = 1;
	return (hit);
}

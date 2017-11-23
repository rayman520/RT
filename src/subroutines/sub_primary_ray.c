/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_primary_rays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 13:06:49 by nthibaud          #+#    #+#             */
/*   Updated: 2017/11/08 14:40:29 by mulzega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	fill_c2w_matrix(double **m, t_v3d from, t_v3d to)
{
	t_v3d	x;
	t_v3d	y;
	t_v3d	z;
	t_v3d	w;
	t_v3d	tmp;

	v3d_set(&tmp, 0, 1, 0);
	z = v_norm(v_sub_a_by_b(from, to));
	x = v_cross(tmp, z);
	y = v_cross(z, x);
	w = from;
	m_row_fill(m, x, 0, 0);
	m_row_fill(m, y, 1, 0);
	m_row_fill(m, z, 2, 0);
	m_row_fill(m, w, 3, 1);
}

void	fill_rot_matrix(double **m, double angle, int xy)
{
	t_v3d	x;
	t_v3d	y;
	t_v3d	z;
	t_v3d	w;

	if (xy == 0)
	{
		v3d_set(&y, 0, 1, 0);
		v3d_set(&x, cos(angle), 0, -sin(angle));
		v3d_set(&z, sin(angle), 0, cos(angle));
	}
	else
	{
		v3d_set(&x, 1, 0, 0);
		v3d_set(&y, 0, cos(angle), sin(angle));
		v3d_set(&z, 0, -sin(angle), cos(angle));
	}
	v3d_set(&w, 0, 0, 0);
	m_row_fill(m, x, 0, 0);
	m_row_fill(m, y, 1, 0);
	m_row_fill(m, z, 2, 0);
	m_row_fill(m, w, 3, 1);
}

void	build_rot_matrix(t_rot *r, double angle)
{
	double	**m_right;
	double	**m_left;
	double	**m_up;
	double	**m_down;

	m_right = m_allocate();
	m_left = m_allocate();
	m_up = m_allocate();
	m_down = m_allocate();
	r->m_rot_up = m_up;
	r->m_rot_down = m_down;
	r->m_rot_right = m_right;
	r->m_rot_left = m_left;
}

void	fill_forward_backward_m(double **m, t_env *e, t_v3d w)
{
	t_v3d	x;
	t_v3d	y;
	t_v3d	z;

	v3d_set(&x, 1, 0, 0);
	v3d_set(&y, 0, 1, 0);
	v3d_set(&z, 0, 0, 1);
	v3d_set(&w, w.x, w.y, w.z);
	m_row_fill(m, x, 0, 0);
	m_row_fill(m, y, 1, 0);
	m_row_fill(m, z, 2, 0);
	m_row_fill(m, w, 3, 1);
}

void	pscreen_to_pcam(t_env *e, t_v3d *v)
{
	v->x = (2 * ((v->x + 0.5) / e->width) - 1) * tan(0.52 / 2);
	v->y = (1 - 2 * ((v->y + 0.5) / e->height)) * tan(0.52 / 2);
	if (e->width > e->height)
		v->x = v->x * e->width / e->height;
	else if (e->width < e->height)
		v->y = v->y * e->height / e->width;
}

void	fill_transltion_matrix(t_env *e, t_ray *ray)
{
	t_v3d	d;
	t_v3d	o;
	t_v3d	w;

	v3d_set(&d, 0, 0, 0);
	o = ray->o.v;
	w = v_mult(v_norm(v_sub_a_by_b(o, d)), e->b_incr);
	fill_forward_backward_m(e->backward_m, e, w);
	w = v_mult(v_norm(v_sub_a_by_b(d, o)), e->f_incr);
	fill_forward_backward_m(e->forward_m, e, w);
}

t_v3d	forward_backward_translation(t_env *e, t_v3d v)
{
	if (e->up_down == 1)
	{
		v = m_x_v(e->backward_m, v);
		v = m_x_v(e->forward_m, v);
	}
	if (e->up_down == 0)
	{
		v = m_x_v(e->forward_m, v);
		v = m_x_v(e->backward_m, v);
	}
	return (v);
}

void	cast_primary_rays(t_env *e)
{
	t_v3d	p;
	t_ray	ray;
	int		x;
	int		y;

	y = 0;
	r_set_to_zero(&ray);
	ray.o.v = m_x_v(e->c2w, ray.o.v);
	ray.o.v = m_x_v(e->rot_m, ray.o.v);
	fill_transltion_matrix(e, &ray);
	ray.o.v = forward_backward_translation(e, ray.o.v);
	while (y <= e->height)
	{
		x = 0;
		while (x < e->width)
		{
			v3d_set(&p, x, y, -1);
			pscreen_to_pcam(e, &p);
			p = m_x_v(e->c2w, p);
			p = m_x_v(e->rot_m, p);
			p = forward_backward_translation(e, p);
			ray.d.v = v_sub_a_by_b(p, ray.o.v);
			ray.d.nv = v_norm(ray.d.v);
			primary_inter(e, ray, x, y);
			x = x + e->aliasing;
		}
		y = y + e->aliasing;
	}
}

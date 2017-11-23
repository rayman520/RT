/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_primary_rays.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 13:06:49 by nthibaud          #+#    #+#             */
/*   Updated: 2017/11/23 11:11:31 by nthibaud         ###   ########.fr       */
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

void	build_c2w(double **c2w, t_vect cam)
{
	t_3d_double	tmp;
	t_3d_double forward;
	t_3d_double	right;
	t_3d_double	up;
	t_m_rows	rows;

	tmp = (t_3d_double){0,1,0};
	forward = v_norm(v_sub_a_by_b(cam.pos, cam.dir));
	right = v_cross(tmp, forward);
	up = v_cross(forward, right);
	rows.x_row = forward;
	rows.y_row = right;
	rows.z_row = up;
	rows.w_row = (t_3d_double){0,0,0};
}

void	pscreen_to_pcam(SDL_Surface *img, t_3d_double *v)
{
	v->x = (2 * ((v->x + 0.5) / img->w) - 1) * tan(0.52 / 2);
	v->y = (1 - 2 * ((v->y + 0.5) / img->h)) * tan(0.52 / 2);
	if (img->w > img->h)
		v->x = v->x * img->w / img->h;
	else if (img->w < img->h)
		v->y = v->y * img->h / img->w;
}

void	cast_primary_rays(t_fullmap *map, t_SDL_Bundle b)
{
	t_v3d	p;
	t_ray	ray;
	t_2dint	pos;
	double		**c2w;

	m4_allocate(c2w);
	build_c2w(c2w, map->camera[map->target_cam]);
	pos.y = -1;
	r_set_to_zero(&ray);
	ray.o.v = m_x_v(e->c2w, ray.o.v);
	while (++pos.y <= b.render_img->h)
	{
		pos.x = -1;
		while (++pos.x < b.render_img->w)
		{
			v3d_set(&p, x, y, -1);
			pscreen_to_pcam(e, &p);
			p = m_x_v(e->c2w, p);
			ray.d.v = v_sub_a_by_b(p, ray.o.v);
			ray.d.nv = v_norm(ray.d.v);
			primary_inter(e, ray, x, y);
		}
	}
}

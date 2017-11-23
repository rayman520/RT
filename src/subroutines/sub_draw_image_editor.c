/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_draw_image_editor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:57:29 by cpierre           #+#    #+#             */
/*   Updated: 2017/11/23 11:11:20 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vect calc_pix_vect(t_cam_vects cam, t_2dint pos, SDL_Surface *img)
{
	t_vect out;
	double percent_x;
	double percent_y;
	double panel_dist;

	out.pos = cam.start.pos;
	percent_x = (t_d)pos.x / (t_d)img->w - 0.5;
	percent_y = (t_d)pos.y / (t_d)img->h - 0.5;
	panel_dist = 10 / (cam.fov / 2);
	out.dir.x = cam.start.dir.x * panel_dist;
	out.dir.y = cam.start.dir.y * panel_dist;
	out.dir.z = cam.start.dir.z * panel_dist;
	out.dir.x += cam.right.dir.x * percent_x;
	out.dir.y += cam.right.dir.y * percent_x;
	out.dir.z += cam.right.dir.z * percent_x;
	out.dir.x += cam.down.dir.x * percent_y * ((t_d)img->h / (t_d)img->w);
	out.dir.y += cam.down.dir.y * percent_y * ((t_d)img->h / (t_d)img->w);
	out.dir.z += cam.down.dir.z * percent_y * ((t_d)img->h / (t_d)img->w);
	out = ft_unit_vect(out);
	return (out);
}
/*
void	pscreen_to_pcam(SDL_Surface *img, t_3d_double *v)
{
	v->x = (2 * ((v->x + 0.5) / img->w) - 1) * tan(0.52 / 2);
	v->y = (1 - 2 * ((v->y + 0.5) / img->h)) * tan(0.52 / 2);
	if (img->w > img->h)
		v->x = v->x * img->w / img->h;
	else if (img->w < img->h)
		v->y = v->y * img->h / img->w;
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
	m4_fill(c2w, rows);
}
*/
void	sub_draw_image_editor(t_fullmap *map, SDL_Surface *img)
{
//	double		**c2w;
	t_2dint		c;
	t_vect		pix_vect;

//	m4_allocate(c2w);
//	build_c2w(c2w, map->camera[map->target_cam]);
	map->cam_v = sub_calc_cam_vects(map->camera[map->target_cam], img->w, img->h);
	map->cam_v.fov = map->fov;
	display_cam_vects("cam_v", map->cam_v);
	c.y = 0;
	while (c.y < img->h)
	{
		c.x = 0;
		while (c.x < img->w)
		{
			pix_vect = calc_pix_vect(map->cam_v, c, img);
			ft_putunlckpixel(img, c, raytrace_editor(map, pix_vect));
			c.x++;
		}
		c.y++;
	}
}

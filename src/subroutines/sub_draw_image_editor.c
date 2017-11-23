/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_draw_image_editor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:57:29 by cpierre           #+#    #+#             */
/*   Updated: 2017/11/23 10:03:39 by nthibaud         ###   ########.fr       */
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

void	sub_draw_image_editor(t_fullmap *map, SDL_Surface *img)
{
	t_2dint		c;
	t_vect		pix_vect;

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

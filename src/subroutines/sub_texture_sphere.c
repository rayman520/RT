/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_texture_sphere.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 16:54:56 by cpierre           #+#    #+#             */
/*   Updated: 2018/01/10 11:45:35 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

Uint32 getpixel(SDL_Surface *img, int x, int y)
{
	Uint32	*pixels;
	Uint8	*pixel;
	t_3d_double	c;

	pixels = (Uint32 *)img->pixels;
	pixel = (Uint8 *)&pixels[(y * 4) * img->w + x * 4];
	c.z = pixel[2];
	c.y = pixel[1];
	c.x = pixel[0];
	return ft_rgb_to_int(c);
}

t_ui				sub_texture_sphere(t_hit hit)
{
	double 	phi;
	double 	theta;

	theta = atan2((double)(hit.pos.y - hit.obj->pos.y), (double)(hit.pos.x - hit.obj->pos.x));
	while (theta > 2 * M_PI)
		theta -= 2 * M_PI;
	phi = acos((double)(hit.pos.z - hit.obj->pos.z) / hit.obj->radius);
	theta = (theta / (double)(2 * M_PI)) * (double)hit.obj->texture->w / (double)4;
	phi = phi / M_PI * hit.obj->texture->h / 4;
	return (getpixel(hit.obj->texture, (int)theta + 1, (int)phi + 1));
}

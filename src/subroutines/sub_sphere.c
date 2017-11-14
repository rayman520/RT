/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 16:54:56 by cpierre           #+#    #+#             */
/*   Updated: 2017/10/20 17:59:50 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

Uint32 getpixel(SDL_Surface *img, int x, int y)
{
	Uint32	*pixels;
	Uint8	*pixel;
	t_rgb	c;

	pixels = (Uint32 *)img->pixels;
	pixel = (Uint8 *)&pixels[(y * 3) * img->w + x * 3];
	c.r = pixel[3];
	c.g = pixel[1];
	c.b = pixel[2];
	return ft_rgb_to_int(c);
}

static t_3d_double	get_normal_vect(t_hit hit)
{
	t_3d_double	out;

	out.x = (hit.pos.x - hit.obj->pos.x) / hit.obj->radius;
	out.y = (hit.pos.y - hit.obj->pos.y) / hit.obj->radius;
	out.z = (hit.pos.z - hit.obj->pos.z) / hit.obj->radius;
	return (out);
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

t_hit				sub_intersect_sphere(t_object *obj, t_vect ray)
{
	t_3d_double	d;
	t_hit		out;

	d.x = ray.dir.x * ray.dir.x + ray.dir.y * ray.dir.y + ray.dir.z * ray.dir.z;
	d.y = 2 * ray.dir.x * (ray.pos.x - obj->pos.x) + 2 * ray.dir.y * (ray.pos.y - obj->pos.y) + 2 * ray.dir.z * (ray.pos.z - obj->pos.z);
	d.z = obj->pos.x * obj->pos.x + obj->pos.y * obj->pos.y + obj->pos.z * obj->pos.z + ray.pos.x * ray.pos.x + ray.pos.y * ray.pos.y + ray.pos.z * ray.pos.z - 2 * (obj->pos.x * ray.pos.x + obj->pos.y * ray.pos.y + obj->pos.z * ray.pos.z) - obj->radius * obj->radius;
	d.z = ft_descriminent(d.x, d.y, d.z);
	if (d.z < 0)
		return (NULL_HIT);
	else
	{
		out.obj = obj;
		out.incident_vect = ray;
		out.dist = (-d.y - sqrt(d.z)) / (2 * d.x);
		if (out.dist < 0)
			out.dist = (-d.y + sqrt(d.z)) / (2 * d.x);
		if (out.dist < 0)
			return (NULL_HIT);
		out.pos = (t_3d_double){ray.pos.x + (ray.dir.x * out.dist), ray.pos.y + (ray.dir.y * out.dist), ray.pos.z + (ray.dir.z * out.dist)};
		out.normal_dir = get_normal_vect(out);
		return (out);
	}
}

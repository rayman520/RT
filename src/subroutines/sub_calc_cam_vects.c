/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_calc_cam_vects.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 16:24:37 by cpierre           #+#    #+#             */
/*   Updated: 2017/10/04 13:27:56 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_vect	get_normal_of_two_vects(t_vect v1, t_vect v2)
{
	t_vect out;

	out.pos = (t_3d_double){0, 0, 0};
	out.dir.x = (v1.dir.y * v2.dir.z - v1.dir.z * v2.dir.y) * -1;
	out.dir.y = (v1.dir.z * v2.dir.x - v1.dir.x * v2.dir.z) * -1;
	out.dir.z = (v1.dir.x * v2.dir.y - v1.dir.y * v2.dir.x) * -1;
	out = ft_unit_vect(out);
	return (out);
}

t_cam_vects	sub_calc_cam_vects(t_vect cam, int img_x, int img_y)
{
	t_cam_vects out;

	out.start.dir.x = cam.dir.x;
	out.start.dir.y = cam.dir.y;
	out.start.dir.z = cam.dir.z;
	out.start.pos = cam.pos;
	out.start = ft_unit_vect(out.start);
	out.right.pos = out.start.pos;
	out.right.dir = (t_3d_double){cam.dir.y, -cam.dir.x, 0};
	if (ft_double_to_int(ft_dot_product(cam, out.right)))
		out.right.dir = (t_3d_double){-cam.dir.z, 0, cam.dir.x};
	out.right = ft_unit_vect(out.right);
	out.down = get_normal_of_two_vects(out.right, cam);
	out.down.pos = out.start.pos;
	img_x = img_y;
	return (out);
}

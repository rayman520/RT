/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_calc_pix_vect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:33:52 by nthibaud          #+#    #+#             */
/*   Updated: 2018/02/19 17:20:10 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vect	sub_calc_pix_vect(t_cam_vects cam, t_2dint pos, int img_w, int img_h)
{
	t_vect out;
	double percent_x;
	double percent_y;
	double panel_dist;

	out.pos = cam.start.pos;
	percent_x = (t_d)pos.x / (t_d)img_w - 0.5;
	percent_y = (t_d)pos.y / (t_d)img_h - 0.5;
	panel_dist = 10 / (cam.fov / 2);
	out.dir.x = cam.start.dir.x * panel_dist;
	out.dir.y = cam.start.dir.y * panel_dist;
	out.dir.z = cam.start.dir.z * panel_dist;
	out.dir.x += cam.right.dir.x * percent_x;
	out.dir.y += cam.right.dir.y * percent_x;
	out.dir.z += cam.right.dir.z * percent_x;
	out.dir.x += cam.down.dir.x * percent_y * ((t_d)img_h / (t_d)img_w);
	out.dir.y += cam.down.dir.y * percent_y * ((t_d)img_h / (t_d)img_w);
	out.dir.z += cam.down.dir.z * percent_y * ((t_d)img_h / (t_d)img_w);
	out = ft_unit_vect(out);
	return (out);
}

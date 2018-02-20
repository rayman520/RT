/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_move_cam_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:09:41 by cpierre           #+#    #+#             */
/*   Updated: 2018/02/20 10:20:32 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	sub_mv_cdir_add(t_vect *cam, t_3d_double dir, double speed)
{
	cam->dir.x += dir.x / 20 * speed;
	cam->dir.y += dir.y / 20 * speed;
	cam->dir.z += dir.z / 20 * speed;
}

void	sub_mv_cdir_sub(t_vect *cam, t_3d_double dir, double speed)
{
	cam->dir.x -= dir.x / 20 * speed;
	cam->dir.y -= dir.y / 20 * speed;
	cam->dir.z -= dir.z / 20 * speed;
}

void	sub_mv_cdir_up(t_vect *cam, t_3d_double dir, double speed)
{
	static t_vect	v_vect;

	v_vect = (t_vect){NULL_POS, (t_3d_double){0, 0, 1}, (t_3d_double){0, 0, 0}};
	if (ft_dot_product(ft_unit_vect(*cam), ft_unit_vect(v_vect)) < 0.95)
		sub_mv_cdir_sub(cam, dir, speed);
}

void	sub_mv_cdir_down(t_vect *cam, t_3d_double dir, double speed)
{
	static t_vect	v_vect;

	v_vect = (t_vect){NULL_POS, (t_3d_double){0, 0, 1}, (t_3d_double){0, 0, 0}};
	if (ft_dot_product(ft_unit_vect(*cam), ft_unit_vect(v_vect)) > -0.95)
		sub_mv_cdir_add(cam, dir, speed);
}

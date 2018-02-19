/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_move_cam_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:31:53 by cpierre           #+#    #+#             */
/*   Updated: 2018/02/19 17:21:16 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	sub_mv_cpos_add(t_vect *cam, t_3d_double dir, double speed)
{
	t_vect new_vect;

	new_vect.pos = (t_3d_double){0, 0, 0};
	new_vect.dir = (t_3d_double){dir.x, dir.y, 0};
	new_vect = ft_unit_vect(new_vect);
	cam->pos.x += new_vect.dir.x / 15 * speed;
	cam->pos.y += new_vect.dir.y / 15 * speed;
}

void	sub_mv_cpos_sub(t_vect *cam, t_3d_double dir, double speed)
{
	t_vect new_vect;

	new_vect.pos = (t_3d_double){0, 0, 0};
	new_vect.dir = (t_3d_double){dir.x, dir.y, 0};
	new_vect = ft_unit_vect(new_vect);
	cam->pos.x -= new_vect.dir.x / 15 * speed;
	cam->pos.y -= new_vect.dir.y / 15 * speed;
}

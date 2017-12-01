/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_handle_keyboard.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 21:36:54 by cpierre           #+#    #+#             */
/*   Updated: 2017/12/01 16:05:25 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	sub_handle_keyboard(t_kp kp, t_fullmap *map)
{
	t_vect	*cam;
	static double cspeed = 0.1;

	cam = &map->camera[map->target_cam];
	if (kp[SDLK_ESCAPE])
			ft_exit("ESCAPE BUTTON EVENT\n");
	if (kp[SDLK_r])
		map->render_key = (map->render_key == 1 ? 0 : 1);
	if (map->render_key == 1)
		return;
	if (kp[SDLK_RIGHT])
		sub_mv_cdir_add(cam, map->cam_v.right.dir, (cspeed < 1 ? cspeed : 1));
	if (kp[SDLK_LEFT])
		sub_mv_cdir_sub(cam, map->cam_v.right.dir, (cspeed < 1 ? cspeed : 1));
	if (kp[SDLK_UP])
		sub_mv_cdir_up(cam, map->cam_v.down.dir, (cspeed < 1 ? cspeed : 1));
	if (kp[SDLK_DOWN])
		sub_mv_cdir_down(cam, map->cam_v.down.dir, (cspeed < 1 ? cspeed : 1));
	if (kp[SDLK_d])
		sub_mv_cpos_add(cam, map->cam_v.right.dir, cspeed);
	if (kp[SDLK_a])
		sub_mv_cpos_sub(cam, map->cam_v.right.dir, cspeed);
	if (kp[SDLK_w])
		sub_mv_cpos_add(cam, map->cam_v.start.dir, cspeed);
	if (kp[SDLK_s])
		sub_mv_cpos_sub(cam, map->cam_v.start.dir, cspeed);
	if (kp[SDLK_SPACE])
		cam->pos.z += cspeed / 10;
	if (kp[SDLK_x])
		cam->pos.z -= cspeed / 10;
	if (kp[SDLK_o])
		cspeed *= 1.2;
	if (kp[SDLK_l])
		cspeed /= 1.2;
	if (kp[SDLK_p] && map->fov < 180)
		map->fov *= 1.1;
	if (kp[SDLK_m] && map->fov > 10)
		map->fov /= 1.1;
}

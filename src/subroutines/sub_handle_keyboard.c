/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_handle_keyboard.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 21:1806:54 by cpierre           #+#    #+#             */
/*   Updated: 2017/12/04 16:52:59 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void        ft_move_obj(t_kp kp, t_fullmap *map)
{
	if (kp[SDLK_KP_4])
		map->obj[map->o].pos.y = map->obj[map->o].pos.y + 0.25;
	if (kp[SDLK_KP_6])
		map->obj[map->o].pos.y = map->obj[map->o].pos.y - 0.25;
	if (kp[SDLK_KP_1])
		map->obj[map->o].pos.x = map->obj[map->o].pos.x - 0.25;
	if (kp[SDLK_KP_9])
		map->obj[map->o].pos.x = map->obj[map->o].pos.x + 0.25;
	if (kp[SDLK_KP_8])
		map->obj[map->o].pos.z = map->obj[map->o].pos.z + 0.25;
	if (kp[SDLK_KP_2])
		map->obj[map->o].pos.z = map->obj[map->o].pos.z - 0.25;
}

void        ft_ray_obj(t_kp kp, t_fullmap *map)
{
	if (kp[SDLK_MINUS] && map->obj[map->o].color == 16777215 &&
		map->obj[map->o].type != 4 && map->obj[map->o].radius > 0)
		map->obj[map->o].radius = map->obj[map->o].radius - 0.5;
	if (kp[SDLK_EQUALS] && map->obj[map->o].color == 16777215 &&
		map->obj[map->o].type != 4)
		map->obj[map->o].radius = map->obj[map->o].radius + 0.5;
}

void        select_obj(t_kp kp, t_fullmap *map)
{
	t_3d_double out;

	if (kp[SDLK_1] && map->o < map->obj_c - 1)
	{
		map->o++;
		if (map->o >= 1)
			map->obj[map->o - 1].color = map->col;
		map->col = map->obj[map->o].color;
		map->obj[map->o].color = 16777215;
	}
	if (kp[SDLK_2] && map->o > 0)
	{
		map->o--;
		map->obj[map->o + 1].color = map->col;
		map->col = map->obj[map->o].color;
		map->obj[map->o].color = 16777215;
	}
	if (kp[SDLK_3])
	{
		map->obj[map->o].color = map->col;
		map->o = -1;
	}
	ft_ray_obj(kp, map);
	ft_move_obj(kp, map);
	SDL_Delay(150);
}

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
	select_obj(kp, map);
}

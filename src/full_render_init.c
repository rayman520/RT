/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_render_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:24:35 by nthibaud          #+#    #+#             */
/*   Updated: 2018/03/05 15:08:03 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	full_render_init(t_str mapfile, t_fullmap *map)
{
	SDL_Window	*render_win;
	SDL_Surface *window_img;
	SDL_Surface *rend_img;

	mkdir("renders", 0777);
	render_win = sub_create_render_window(mapfile, RENDER_WIN_WIDTH,
		RENDER_WIN_HEIGHT);
	window_img = SDL_GetWindowSurface(render_win);
	rend_img = SDL_CreateRGBSurface(0,
		RENDER_WIN_WIDTH, RENDER_WIN_HEIGHT, 32, 0, 0, 0, 0);
	map->cam_v = sub_calc_cam_vects(map->camera[map->target_cam],
		rend_img->w, rend_img->h);
	map->cam_v.fov = map->fov;
	full_render_start((t_sdl_bundle){render_win, window_img, rend_img},
		map, mapfile);
	sub_fullrender_end(render_win, window_img);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_render_from_edit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:26:10 by nthibaud          #+#    #+#             */
/*   Updated: 2018/03/05 15:08:23 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	full_render_from_edit(t_str mapfile, t_fullmap *map,
		t_sdl_bundle b, t_kp kp)
{
	SDL_Surface *render_img;

	b.render_win = sub_create_render_window("Editor", RENDER_WIN_WIDTH,
		RENDER_WIN_HEIGHT);
	b.window_img = SDL_GetWindowSurface(b.render_win);
	render_img = SDL_CreateRGBSurface(0, RENDER_WIN_WIDTH, RENDER_WIN_HEIGHT,
		32, 0, 0, 0, 0);
	full_render_start((t_sdl_bundle){b.render_win, b.window_img, render_img},
		map, mapfile);
	while (map->render_key == 1)
	{
		ft_handle_events(kp);
		sub_handle_keyboard(kp, map);
	}
	SDL_Delay(300);
}

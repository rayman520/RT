/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 16:31:06 by cpierre           #+#    #+#             */
/*   Updated: 2017/12/04 14:42:18 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	init(t_fullmap *map)
{
	map->render_key = 0;
//	map->obj[1].i = 0;
}

static void	obj_movements(t_fullmap *map)
{
//	map->obj[1].i = map->obj[1].i + 1;
//	map->obj[1].pos.x = 2 * cos((double)map->obj[1].i / 100);
//	map->obj[1].pos.y = 2 * sin((double)map->obj[1].i / 100);
	//	map->light[0].pos.x = 1 * cos((double)map->obj[1].i / 100);
	//	map->light[0].pos.y = 1 * sin((double)map->obj[1].i / 100);
}

static void	launch_raytrace(t_fullmap *map, SDL_Window *render_win,
	SDL_Surface *render_img, SDL_Surface *win_img)
{
	obj_movements(map);
	sub_draw_image_editor(map, render_img);
	sub_blit_render(render_img, win_img);
	SDL_UpdateWindowSurface(render_win);
	render_options_win(map);
}

void		editor_start(t_str mapfile, t_fullmap *map)
{
	SDL_Window	*render_win;
	SDL_Surface	*render_img;
	SDL_Surface	*win_img;
	t_kp		kp;

	init(map);
	render_win = sub_create_render_window("Editor", EDITOR_WIN_WIDTH,
		EDITOR_WIN_HEIGHT);
	win_img = SDL_GetWindowSurface(render_win);
	render_img = SDL_CreateRGBSurface(0, map->editres.x, map->editres.y,
		32, 0, 0, 0, 0);
	if (!(kp = (t_kp)malloc(sizeof(short) * 1073742106)))
		ft_exit("ERR_MLC");
	while (1)
	{
		ft_handle_events(kp);
		sub_handle_keyboard(kp, map);
		if (map->render_key == 1)
			full_render_from_edit(mapfile, map, (t_SDL_Bundle){render_win,
			win_img, render_img}, kp);
		launch_raytrace(map, render_win, render_img, win_img);
		sub_put_fps(&render_img, &map->fps, win_img);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_win.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:33:29 by cpierre           #+#    #+#             */
/*   Updated: 2017/11/06 14:14:05 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void create_win(SDL_Window *win, SDL_Surface *img)
{
	t_str		text;
	static int	already_done = 0;

	if (!already_done)
	{
		text = ft_strjoin("RT - options", "");
		win = SDL_CreateWindow(text, 1100, 0, OPT_WIN_W, OPT_WIN_H, 0);
		free(text);
		if (!win)
			ft_exit("Failed to create window");
		img = SDL_GetWindowSurface(win);
		already_done = 1;
	}
}

void render_options_win(t_fullmap *map)
{
	static	SDL_Window	*win = NULL;
	static	SDL_Surface *win_img = NULL;

	create_win(win, win_img);
	map->fps.x = map->fps.x;
	SDL_UpdateWindowSurface(win);
}

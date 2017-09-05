/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 14:04:34 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/05 22:07:38 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	full_render_start(t_str mapfile)
{
	SDL_Window	*render_win;
	SDL_Surface *window_img;
	t_str		title;
	int			i;

	title = ft_strjoin("RT - render ", mapfile);
	render_win = SDL_CreateWindow(title, 0, 0, 1280, 800, 0);
	free(title);
	if (!render_win)
		ft_exit("Failed to create window");
	window_img = SDL_GetWindowSurface(render_win);
	ft_putchar('0' + (char)window_img->format->BytesPerPixel);
	i = -1;
	while (++i <= 1280 * 800)
	{
		ft_handle_events();
		ft_putpixel(window_img, (t_2dint){i % 1280, i / 1280}, 0x007fff - i % 122);
		if (i % (1280 * 800 / 1000) == 0)
			SDL_UpdateWindowSurface(render_win);
	}
	SDL_Delay(2000);
	SDL_DestroyWindow(render_win);
}

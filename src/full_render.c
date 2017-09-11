/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 14:04:34 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/11 16:38:04 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	full_render_start(t_str mapfile)
{
	SDL_Window	*render_win;
	SDL_Surface *window_img;
	SDL_Surface *render_img;
	int			i;

	render_win = sub_create_render_window(mapfile);
	window_img = SDL_GetWindowSurface(render_win);
	render_img = SDL_CreateRGBSurface(0, 1280, 1500, 32, 0, 0, 0, 0);
	i = -1;
	SDL_LockSurface(render_img);
	while (++i <= 1280 * 1500)
	{
		ft_handle_events();
		ft_putunlckpixel(render_img, (t_2dint){i % 1280, i / 1280}, 0x00007fff);
		ft_putunlckpixel(render_img, (t_2dint){5, 5}, 0x00ff0000);
		printf("%.3f%%\r", (double)i / (1280 * 1500) * 100);
	}
	SDL_UnlockSurface(render_img);
	sub_blit_render(render_img, window_img);
	SDL_UpdateWindowSurface(render_win);
	i = -1;
	while (++i < 50000)
	{
		ft_handle_events();
		SDL_Delay(5);
	}
	SDL_DestroyWindow(render_win);
}

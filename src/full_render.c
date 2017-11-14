/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 14:04:34 by cpierre           #+#    #+#             */
/*   Updated: 2017/11/14 14:57:02 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static Uint32 full_render_pixel(t_2dint pos, t_fullmap *map)
{
	pos.x = pos.y;
	map->obj = map->obj;
	return(0xffffff);
}

static void full_render_image(t_SDL_Bundle b, t_fullmap *map, int i, int image_number)
{
	t_2dint	pos;

	SDL_LockSurface(b.render_img);
	pos.y = -1;
	while (++pos.y < b.render_img->h)
	{
		pos.x = -1;
		while (++pos.x < b.render_img->w)
		{
			ft_handle_events(NULL);
			ft_putunlckpixel(b.render_img, pos, full_render_pixel(pos, map));
		}
		sub_put_percent(b.render_win, b.window_img, 100 * (double)(pos.y + i * b.render_img->h) / (b.render_img->h * image_number));
	}
	SDL_UnlockSurface(b.render_img);
}

void	full_render_start(t_str mapfile)
{
	t_2dint		img_size;
	int			image_number = 8;
	SDL_Window	*render_win;
	SDL_Surface *window_img;
	SDL_Surface *render_img;
	int			i;
	t_str		savefile_name;
	t_str		tmp;
	t_fullmap	*map;

	img_size.x = 500;
	img_size.y = 500;
	map = parser(mapfile);
	render_win = sub_create_render_window(mapfile,
			RENDER_WIN_WIDTH, RENDER_WIN_HEIGHT);
	window_img = SDL_GetWindowSurface(render_win);
	render_img = SDL_CreateRGBSurface(0, img_size.x, img_size.y, 32, 0, 0, 0, 0);
	i = 0;
	while (i < image_number)
	{
		full_render_image((t_SDL_Bundle){render_win, window_img, render_img}, map, i, image_number);
		mkdir("renders", 0777);
		savefile_name = ft_strjoin("renders\\RT_Full-render_", mapfile);
		tmp = ft_strjoin(savefile_name, ft_itoa(i));
		savefile_name = ft_strjoin(tmp, ".bmp");
		free(tmp);
		ft_str_replace(savefile_name, '/', '_');
		ft_str_replace(savefile_name, '\\', '/');
		SDL_SaveBMP(render_img, savefile_name);
		printf("%s", SDL_GetError());
		free(savefile_name);
		sub_blit_render(render_img, window_img);
		SDL_UpdateWindowSurface(render_win);
		i++;
	}
	sub_fullrender_end(render_win, window_img);
}

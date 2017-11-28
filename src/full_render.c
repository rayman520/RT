/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 14:04:34 by cpierre           #+#    #+#             */
/*   Updated: 2017/11/23 10:43:42 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	save_image(SDL_Surface *img, int i, t_str mapfile)
{
	t_str	savefile_name;
	t_str	tmp;

	savefile_name = ft_strjoin("renders\\RT_Full-render_", mapfile);
	tmp = ft_strjoin(savefile_name, ft_itoa(i));
	savefile_name = ft_strjoin(tmp, ".bmp");
	free(tmp);
	ft_str_replace(savefile_name, '/', '_');
	ft_str_replace(savefile_name, '\\', '/');
	SDL_SaveBMP(img, savefile_name);
	printf("%s", SDL_GetError());
	free(savefile_name);
}

static Uint32 full_render_pixel(t_2dint pos, t_fullmap *map)
{
	pos.x = pos.y;
	map->obj = map->obj;
	return(0x000050);
}

static void full_render_images(t_SDL_Bundle b, t_fullmap *map, t_str mapfile)
{
	t_2dint	pos;
	int i;
	int image_number = 1;

	i = 0;
	while (i < image_number)
	{
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
		save_image(b.render_img, i, mapfile);
		sub_blit_render(b.render_img, b.window_img);
		SDL_UpdateWindowSurface(b.render_win);
		i++;
	}
}

void	full_render_start(t_str mapfile)
{
	SDL_Window	*render_win;
	SDL_Surface *window_img;
	SDL_Surface *render_img;
	SDL_version	ver;
	t_fullmap	*map;

	SDL_GetVersion(&ver);
	printf("%d.%d.%d\n", ver.major, ver.minor, ver.patch);
	map = parser(mapfile);
	mkdir("renders", 0777);
	render_win = sub_create_render_window(mapfile,
			RENDER_WIN_WIDTH, RENDER_WIN_HEIGHT);
	window_img = SDL_GetWindowSurface(render_win);
	render_img = SDL_CreateRGBSurface(0, map->res.x, map->res.y, 32, 0, 0, 0, 0);
	full_render_images((t_SDL_Bundle){render_win, window_img, render_img}, map, mapfile);
	sub_fullrender_end(render_win, window_img);
}

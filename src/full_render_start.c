/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_render_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:28:54 by nthibaud          #+#    #+#             */
/*   Updated: 2017/12/01 16:36:08 by nthibaud         ###   ########.fr       */
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

static void	browse_screen_pixel(t_fullmap *map, t_SDL_Bundle b, int img_nb, int i)
{
	t_2dint		pos;
	t_vect		ray;

	pos.y = -1;
	while (++pos.y < b.render_img->h)
	{
		pos.x = -1;
		while (++pos.x < b.render_img->w)
		{
			ray = sub_calc_pix_vect(map->cam_v, pos, b.render_img);
			ft_putunlckpixel(b.render_img, pos,
				ft_double_3d_to_int(raytrace_fullrender(map, ray)));
		}
		sub_put_percent(b.render_win, b.window_img, 100 * (double)(pos.y +
			i * b.render_img->h) / (b.render_img->h * img_nb));
	}
}

void	full_render_start(t_SDL_Bundle b, t_fullmap *map, t_str mapfile)
{
	int			i;
	int			image_number;

	image_number = 1;
	i = 0;
	while (i < image_number)
	{
		SDL_LockSurface(b.render_img);
		browse_screen_pixel(map, b, image_number, i);
		SDL_UnlockSurface(b.render_img);
		save_image(b.render_img, i, mapfile);
		sub_blit_render(b.render_img, b.window_img);
		SDL_UpdateWindowSurface(b.render_win);
		i++;
	}
}

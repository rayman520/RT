/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 14:04:34 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/24 13:34:53 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	full_render_start(t_str mapfile)
{
	t_2dint		img_size;
	int			image_number = 8;
	SDL_Window	*render_win;
	SDL_Surface *window_img;
	SDL_Surface *render_img;
	int			i;
	t_2dint		cur_pos;
	t_str		savefile_name;
	t_str		tmp;

	img_size.x = 50;
	img_size.y = 50;
	render_win = sub_create_render_window(mapfile);
	window_img = SDL_GetWindowSurface(render_win);
	render_img = SDL_CreateRGBSurface(0, img_size.x, img_size.y, 32, 0, 0, 0, 0);
	i = 0;
	while (i < image_number)
	{
		SDL_LockSurface(render_img);
		cur_pos.y = 0;
		while (cur_pos.y < img_size.y)
		{
			cur_pos.x = 0;
			while (cur_pos.x < img_size.x)
			{
				ft_handle_events();
				ft_putunlckpixel(render_img, cur_pos, (Uint32)(0x00007fff + 0x00770000 * i));
				ft_putunlckpixel(render_img, (t_2dint){5, 5}, 0x00ff0000);
				cur_pos.x++;
			}
			sub_put_percent(render_win, window_img, 100 * (double)(cur_pos.y + i * img_size.y) / (img_size.y * image_number));
			cur_pos.y++;
		}
		SDL_UnlockSurface(render_img);
		mkdir("renders", 0777);
		savefile_name = ft_strjoin("renders/RT_Full-render_", mapfile);
		tmp = ft_strjoin(savefile_name, ft_itoa(i));
		savefile_name = ft_strjoin(tmp, ".bmp");
		free(tmp);
		SDL_SaveBMP(render_img, savefile_name);
		free(savefile_name);
		sub_blit_render(render_img, window_img);
		SDL_UpdateWindowSurface(render_win);
		i++;
	}
	sub_fullrender_end(render_win, window_img);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_render_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:28:54 by nthibaud          #+#    #+#             */
/*   Updated: 2018/02/08 14:55:18 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	save_image(SDL_Surface *img, int i, t_str mapfile)
{
	t_str	savefile_name;
	t_str	tmp;
	t_str	tmp2;

	savefile_name = ft_strjoin("renders\\RT_Full-render_", mapfile);
	tmp2 = ft_itoa(i);
	tmp = ft_strjoin(savefile_name, tmp2);
	free(savefile_name);
	free(tmp2);
	savefile_name = ft_strjoin(tmp, ".bmp");
	free(tmp);
	ft_str_replace(savefile_name, '/', '_');
	ft_str_replace(savefile_name, '\\', '/');
	SDL_SaveBMP(img, savefile_name);
	printf("%s", SDL_GetError());
	free(savefile_name);
}

void		full_render_start(t_SDL_Bundle b, t_fullmap *map, t_str mapfile)
{
	int		i;
	int		image_number;
	Uint32	time_before;
	Uint32	time_after;
	Uint32	time;

	image_number = 1;
	i = 0;
	while (i < image_number)
	{
		SDL_LockSurface(b.render_img);
		time_before = SDL_GetTicks();
		full_render_threads(map, b);
		time_after = SDL_GetTicks();
		time = time_after - time_before;
		printf("FULLRENDER TIME : %d.%d sec\n", time / 1000, time % 1000);
		SDL_UnlockSurface(b.render_img);
		save_image(b.render_img, i, mapfile);
		sub_blit_render(b.render_img, b.window_img);
		SDL_UpdateWindowSurface(b.render_win);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_put_fps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 12:14:01 by cpierre           #+#    #+#             */
/*   Updated: 2018/02/08 15:02:22 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static SDL_Surface *create_surface(int x, int y)
{
	SDL_Surface *out;

	out = SDL_CreateRGBSurface(0, x, y, 32, 0, 0, 0, 0);
	printf("Warning: Resolution changed to %dx%d\n", x, y);
	return (out);
}

static void	realoc_img(SDL_Surface **img, double fps, t_2dint *mapfps)
{
	SDL_Surface		*tmp;
	static double	*aspect_ratio = NULL;
	double			newsize;

	if (!aspect_ratio)
	{
		aspect_ratio = (double *)malloc(sizeof(double));
		if (aspect_ratio != NULL)
			*aspect_ratio = (double)(*img)->h / (double)(*img)->w;
	}
	if (fps < mapfps->x)
	{
		newsize = (t_d)(*img)->w / 1.2;
		if (newsize < 30)
			newsize = 30;
		else if (newsize * *aspect_ratio < 30)
			newsize = 30 / *aspect_ratio;
		tmp = create_surface((int)newsize, (int)(newsize * *aspect_ratio));
		SDL_FreeSurface(*img);
		*img = tmp;
	}
	else if (fps > mapfps->y)
	{
		tmp = create_surface((int)((*img)->w * 1.2), (int)((*img)->w * 1.2 * *aspect_ratio));
		SDL_FreeSurface(*img);
		*img = tmp;
	}
}
void	sub_put_fps(SDL_Surface **img, t_2dint *mapfps, SDL_Surface *w)
{
	static Uint32	old_time = 0;
	static short	nb_passed = -1;
	Uint32			cur_time;
	static double	ratio = 0;
	static t_str	str = NULL;

	if (mapfps->x < 5 || mapfps->x > 60)
		mapfps->x = 30;
	if (mapfps->y < mapfps->x || mapfps->y > 120)
		mapfps->y = mapfps->x + 30;
	if (nb_passed == 10 || nb_passed == -1)
	{
		cur_time = SDL_GetTicks();
		ratio = cur_time - old_time;
		if (nb_passed != -1)
			ratio /= 10000;
		else
			ratio /= 1000;
		old_time = cur_time;
		nb_passed = -2;
		realoc_img(img, 1 / ratio, mapfps);
	}
	if (!str)
		str = (t_str)malloc(sizeof(char) * 8);
	sprintf(str, "%.1lf fps", 1 / ratio);
	sub_put_text(w, str);
	nb_passed++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_put_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 12:30:50 by cpierre           #+#    #+#             */
/*   Updated: 2017/10/22 15:07:31 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	sub_put_text(SDL_Surface *img, t_str text)
{
	SDL_Surface			*surface;
	static SDL_Rect		*rect = NULL;
	static TTF_Font		*font = NULL;
	static SDL_Color	color = {255, 255, 255, 0};

	if (!font)
		font = TTF_OpenFont("ressources/upheavtt.ttf", 12);
	if (!rect)
	{
		if (!(rect = (SDL_Rect *)malloc(sizeof(SDL_Rect))))
			ft_exit("ERR_MLC\n");
		else
		{
			rect->x = 0;
			rect->y = 0;
			rect->w = 70;
			rect->h = 24;
		}
	}
	SDL_FillRect(img, rect, 0x000000);
	surface = TTF_RenderText_Solid(font, text, color);
	SDL_BlitSurface(surface, NULL, img, rect);
	SDL_FreeSurface(surface);
}

void		sub_put_percent(SDL_Window *win, SDL_Surface *img, double val)
{
	static t_str	percent = NULL;

	if (!percent)
	{
		if (!(percent = (t_str)malloc(sizeof(char) * 8)))
			ft_exit("ERR_MLC");
	}
	else if ((int)(val * 100) % 10 == 0)
	{
		sprintf(percent, "%.1lf %%", val);
		sub_put_text(img, percent);
		SDL_UpdateWindowSurface(win);
	}
}

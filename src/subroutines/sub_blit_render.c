/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_blit_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 15:13:54 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/11 16:14:33 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	sub_blit_render(SDL_Surface *src, SDL_Surface *dst)
{
	float		bigdelt;
	SDL_Rect	rect;

	bigdelt = ft_biggest_fl((float)dst->w / (float)src->w,
		(float)dst->h / (float)src->h);
	rect.w = (int)((float)src->w * bigdelt);
	rect.x = (int)(((float)dst->w - (float)rect.w) / 2);
	rect.h = (int)((float)src->h * bigdelt);
	rect.y = (int)(((float)dst->h - (float)rect.h) / 2);
	printf("%d,%d  %d,%d", rect.x, rect.y, rect.w, rect.h);
	SDL_BlitScaled(src, NULL, dst, &rect);
}

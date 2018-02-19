/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunlckpixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 18:03:55 by cpierre           #+#    #+#             */
/*   Updated: 2018/02/19 17:23:55 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	ft_putunlckpixel(SDL_Surface *img, t_2dint pos, Uint32 val)
{
	Uint32	*p;
	int		bpp;

	if (pos.x < 0 || pos.y < 0 || pos.x >= img->w || pos.y >= img->h)
		return (0);
	bpp = img->format->BytesPerPixel;
	if (bpp != 4)
		ft_exit("tried to draw a Uint32 pixel into an image of bpp != 4\n");
	p = (Uint32 *)img->pixels + (pos.y * img->pitch / bpp + pos.x);
	*p = (Uint32)val;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunlckpixel.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 18:03:55 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/05 22:18:57 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			ft_putunlckpixel(SDL_Surface *img, t_2dint pos, Uint32 val)
{
	Uint32	*p;
	int		bpp;

	if (pos.x < 0 || pos.y < 0 || pos.x >= img->w || pos.y >= img->h)
		return (0);
	bpp = img->format->BytesPerPixel;
	p = (Uint32 *)img->pixels + pos.y * img->pitch + pos.x * bpp;
	*p = (Uint32)val;
	return (0);
}

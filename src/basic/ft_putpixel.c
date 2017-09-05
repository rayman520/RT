/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 18:05:37 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/05 16:22:51 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_putpixel(SDL_Surface *img, t_2dint pos, Uint32 val)
{
	SDL_LockSurface(img);
	ft_putunlckpixel(img, pos, val);
	SDL_UnlockSurface(img);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_fullrender_end.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 15:50:39 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/23 16:23:43 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	sub_fullrender_end(SDL_Window *win, SDL_Surface *img)
{
	int i;

	sub_put_percent(win, img, 100);
	i = -1;
	while (++i < 50000)
	{
		ft_handle_events();
		SDL_Delay(5);
	}
	SDL_DestroyWindow(win);
}

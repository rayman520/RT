/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:06:14 by cpierre           #+#    #+#             */
/*   Updated: 2018/02/19 17:23:10 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_handle_events(t_kp kp)
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			ft_event_sdlquit();
		else if (e.type == SDL_WINDOWEVENT)
			ft_handle_windowevent(e.window);
		else if (kp && e.type == SDL_KEYDOWN)
			kp[e.key.keysym.sym] = 1;
		else if (kp && e.type == SDL_KEYUP)
			kp[e.key.keysym.sym] = 0;
	}
}

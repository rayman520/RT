/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_sdlquit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:21:46 by cpierre           #+#    #+#             */
/*   Updated: 2018/03/13 13:07:26 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_event_sdlquit(void)
{
	Uint32 tmp;

	tmp = SDL_GetTicks();
	SDL_Quit();
	ft_exit(NULL);
}

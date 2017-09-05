/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_sdlquit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:21:46 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/05 17:32:21 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_event_sdlquit(void)
{
	Uint32 tmp;

	tmp = SDL_GetTicks();
	SDL_Quit();
	printf("Program terminated after %d ms of runtime\n", tmp);
	ft_exit(NULL);
}

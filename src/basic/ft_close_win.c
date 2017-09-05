/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 18:10:57 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/05 17:32:28 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_close_win(Uint32 id)
{
	printf("Window %d closed\n", id);
	SDL_DestroyWindow(SDL_GetWindowFromID(id));
}

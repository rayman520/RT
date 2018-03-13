/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_win.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 18:10:57 by cpierre           #+#    #+#             */
/*   Updated: 2018/03/13 13:11:29 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_close_win(Uint32 id)
{
	ft_putstr("Window closed\n");
	if (id == 1)
		ft_exit("Program terminated\n");
	SDL_DestroyWindow(SDL_GetWindowFromID(id));
}

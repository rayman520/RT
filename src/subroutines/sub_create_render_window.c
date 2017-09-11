/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_create_render_window.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:25:26 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/11 16:37:47 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

SDL_Window	*sub_create_render_window(t_str mapfile)
{
	SDL_Window	*out;
	t_str		text;

	text = ft_strjoin("RT - render ", mapfile);
	out = SDL_CreateWindow(text, 0, 0, RENDER_WIN_WIDTH, RENDER_WIN_HEIGHT, 0);
	free(text);
	if (!out)
		ft_exit("Failed to create window");
	return (out);
}

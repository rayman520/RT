/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_create_render_window.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 16:25:26 by cpierre           #+#    #+#             */
/*   Updated: 2018/02/19 17:20:26 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

SDL_Window	*sub_create_render_window(t_str mapfile, int sx, int sy)
{
	SDL_Window	*out;
	t_str		text;

	text = ft_strjoin("RT - render ", mapfile);
	out = SDL_CreateWindow(text, 0, 0, sx, sy, 0);
	free(text);
	if (!out)
		ft_exit("Failed to create window");
	return (out);
}

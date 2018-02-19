/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_read_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:56:42 by cpierre           #+#    #+#             */
/*   Updated: 2018/02/19 17:19:38 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

SDL_Surface	*sub_read_texture(t_str file)
{
	SDL_Surface *out;

	out = IMG_Load(file);
	if (!out)
		return (NULL);
	return (out);
}

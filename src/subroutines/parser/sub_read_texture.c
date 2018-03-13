/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_read_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:56:42 by cpierre           #+#    #+#             */
/*   Updated: 2018/03/13 19:18:49 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

SDL_Surface	*sub_read_texture(t_str file)
{
	SDL_Surface *out;

	printf("%s\n", file);
	out = IMG_Load(file);
	if (!out)
		return (NULL);
	return (out);
}

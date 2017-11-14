/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_read_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:56:42 by cpierre           #+#    #+#             */
/*   Updated: 2017/10/20 15:20:35 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

SDL_Surface	*sub_read_texture(t_str file)
{
	SDL_Surface *out;

	out = IMG_Load(file);
	if (!out)
	{
		printf("could not read '%s', no texture set\n", file);
		return (NULL);
	}
	else
		printf("texture set to '%s'\n", file);
	return (out);
}

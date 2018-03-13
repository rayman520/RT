/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_read_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:56:42 by cpierre           #+#    #+#             */
/*   Updated: 2018/03/13 19:39:21 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

SDL_Surface	*sub_read_texture(t_str file)
{
	SDL_Surface *out;

	if (file == NULL || ft_strlen(file) < 1)
		ft_exit("err parser");
	if (!ft_strcmp(file, "none"))
		return (NULL);
	out = IMG_Load(file);
	if (!out)
		return (NULL);
	return (out);
}

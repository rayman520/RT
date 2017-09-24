/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 16:31:06 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/24 13:30:58 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	editor_start(t_str mapfile)
{
	t_fullmap *map;

	map = parser(mapfile);
	printf("EDIT MODE %s", map->mapfile_pathname);
	free(map);
}

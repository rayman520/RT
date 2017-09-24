/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 13:28:16 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/24 13:32:32 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_fullmap	*parser(t_str mapfile)
{
	t_fullmap *map;

	if (!(map = (t_fullmap *)malloc(sizeof(t_fullmap))))
		ft_exit("ERR_MLC");
	map->mapfile_pathname = mapfile;
	return (map);
}

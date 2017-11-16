/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 13:28:16 by cpierre           #+#    #+#             */
/*   Updated: 2017/11/16 14:05:22 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_fullmap	*parser(t_str mapfile)
{
	t_fullmap	*map;
	t_str		tmp;

	map = (t_fullmap *)malloc(sizeof(t_fullmap));
	if (!map)
		return (NULL);
	map->mapfile_pathname = mapfile;
	tmp = ft_strdup("rt");
	if (!sub_check_extension(mapfile, tmp))
		ft_exit(".rt parser not done yet\n");
	free(tmp);
	tmp = ft_strdup("xml");
	if (!sub_check_extension(mapfile, tmp))
		sub_parser_xml(map, xmlReadFile(mapfile, NULL, 0));
	free(tmp);
	tmp = ft_strdup("json");
	if (!sub_check_extension(mapfile, tmp))
		ft_exit(".json parser not done yet\n");
	free(tmp);
	return (map);
}

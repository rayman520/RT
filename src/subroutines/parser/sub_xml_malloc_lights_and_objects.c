/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_xml_malloc_lights_and_objects.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:55:22 by cpierre           #+#    #+#             */
/*   Updated: 2018/03/12 16:53:02 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_light		*sub_malloc_lights(t_fullmap *map, xmlNode *node)
{
	int			i;
	t_light		*out;
	static int	error = 0;

	i = 0;
	while (node)
	{
		if (!ft_strcmp((const char *)node->name, "light"))
			i++;
		if (!ft_strcmp((const char *)node->name, "objects") ||
			!ft_strcmp((const char *)node->name, "lights") ||
			!ft_strcmp((const char *)node->name, "cameras") ||
			!ft_strcmp((const char *)node->name, "camera") ||
			!ft_strcmp((const char *)node->name, "object"))
			ft_exit("object-ception");
		node = node->next;
	}
	if (!(out = (t_light *)malloc(sizeof(t_light) * (t_ul)i)))
		ft_exit("ERR_MLC\n");
	map->light_c = i;
	if (error)
		ft_exit("err_parser");
	error++;
	return (out);
}

t_object	*sub_malloc_objects(t_fullmap *map, xmlNode *node)
{
	int			i;
	t_object	*out;
	static int	error = 0;

	i = 0;
	while (node)
	{
		if (!ft_strcmp((const char *)node->name, "object"))
			i++;
		if (!ft_strcmp((const char *)node->name, "objects") ||
			!ft_strcmp((const char *)node->name, "lights") ||
			!ft_strcmp((const char *)node->name, "cameras") ||
			!ft_strcmp((const char *)node->name, "light") ||
			!ft_strcmp((const char *)node->name, "camera"))
			ft_exit("object-ception");
		node = node->next;
	}
	if (!(out = (t_object *)malloc(sizeof(t_object) * (t_ul)i)))
		ft_exit("ERR_MLC\n");
	map->obj_c = i;
	if (error)
		ft_exit("err_parser");
	error++;
	return (out);
}

t_vect		*sub_malloc_cameras(t_fullmap *map, xmlNode *node)
{
	int			i;
	t_vect		*out;
	static int	error = 0;

	i = 0;
	while (node)
	{
		if (!ft_strcmp((const char *)node->name, "camera"))
			i++;
		if (!ft_strcmp((const char *)node->name, "objects") ||
			!ft_strcmp((const char *)node->name, "lights") ||
			!ft_strcmp((const char *)node->name, "cameras") ||
			!ft_strcmp((const char *)node->name, "light") ||
			!ft_strcmp((const char *)node->name, "object"))
			ft_exit("object-ception");
		node = node->next;
	}
	if (!(out = (t_vect *)malloc(sizeof(t_vect) * (t_ul)i)))
		ft_exit("ERR_MLC\n");
	map->cam_c = i;
	if (error)
		ft_exit("err_parser");
	error++;
	return (out);
}

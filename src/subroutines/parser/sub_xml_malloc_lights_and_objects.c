/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_xml_malloc_lights_and_objects.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 12:55:22 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/29 16:21:32 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_light		*sub_malloc_lights(t_fullmap *map, xmlNode *node)
{
	int		i;
	t_light	*out;

	i = 0;
	while (node)
	{
		if (!ft_strcmp((const char *)node->name, "light"))
			i++;
		node = node->next;
	}
	printf("Reading %d lights\n", i);
	if (!(out = (t_light *)malloc(sizeof(t_light) * (t_ul)i)))
		ft_exit("ERR_MLC\n");
	map->light_c = i;
	if (i == 0)
		printf("Warning: it wont be %s\x1B[32mU\x1B[31mL\x1B[0m\n",
			"\x1B[31mB\x1B[32mE\x1B[33mA\x1B[34mU\x1B[35mT\x1B[34mI\x1B[33mF");
	return (out);
}

t_object	*sub_malloc_objects(t_fullmap *map, xmlNode *node)
{
	int			i;
	t_object	*out;

	i = 0;
	while (node)
	{
		if (!ft_strcmp((const char *)node->name, "object"))
			i++;
		node = node->next;
	}
	printf("Reading %d objects\n", i);
	if (!(out = (t_object *)malloc(sizeof(t_object) * (t_ul)i)))
		ft_exit("ERR_MLC\n");
	map->obj_c = i;
	if (i == 0)
		printf("What's the fucking point?\n");
	return (out);
}

t_vect		*sub_malloc_cameras(t_fullmap *map, xmlNode *node)
{
	int			i;
	t_vect		*out;

	i = 0;
	while (node)
	{
		if (!ft_strcmp((const char *)node->name, "camera"))
			i++;
		node = node->next;
	}
	printf("Reading %d cameras\n", i);
	if (!(out = (t_vect *)malloc(sizeof(t_vect) * (t_ul)i)))
		ft_exit("ERR_MLC\n");
	map->cam_c = i;
	if (i == 0)
		printf("What's the fucking point?\n");
	return (out);
}

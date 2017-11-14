/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_parser_xml.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 17:28:34 by cpierre           #+#    #+#             */
/*   Updated: 2017/10/30 18:46:14 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void options_parser(xmlNode *node, t_fullmap *map)
{
	xmlNode *cur_node;

	cur_node = node;
	while (cur_node)
	{
		if (cur_node->type == XML_ELEMENT_NODE)
		{
			if (!ft_strcmp((const char *)cur_node->name, "resolution"))
				map->res = ft_xml_rd_res((char *)xmlNodeGetContent(cur_node));
			else if (!ft_strcmp((const char *)cur_node->name, "editor_res"))
				map->editres = ft_xml_ed_res((char *)xmlNodeGetContent(cur_node));
			else if (!ft_strcmp((const char *)cur_node->name, "editor_fps_low"))
				map->fps.x = ft_atoi((char *)xmlNodeGetContent(cur_node));
			else if (!ft_strcmp((const char *)cur_node->name, "editor_fps_high"))
				map->fps.y = ft_atoi((char *)xmlNodeGetContent(cur_node));
			else if (!ft_strcmp((const char *)cur_node->name, "fov"))
				map->fov = ft_atoi((char *)xmlNodeGetContent(cur_node));
		}
		cur_node = cur_node->next;
	}
}

static void	recursive_parser(xmlNode *node, t_fullmap *map)
{
	xmlNode *cur_node;

	cur_node = node;
	while (cur_node)
	{
		if (cur_node->type == XML_ELEMENT_NODE)
		{
			if (!ft_strcmp((const char *)cur_node->name, "options"))
				options_parser(cur_node->children, map);
			else if (!ft_strcmp((const char *)cur_node->name, "lights"))
				map->light = sub_malloc_lights(map, cur_node->children);
			else if (!ft_strcmp((const char *)cur_node->name, "objects"))
				map->obj = sub_malloc_objects(map, cur_node->children);
			else if (!ft_strcmp((const char *)cur_node->name, "cameras"))
				map->camera = sub_malloc_cameras(map, cur_node->children);
			else if (!ft_strcmp((const char *)cur_node->name, "light"))
				sub_xml_read_light(map->light, cur_node->children);
			else if (!ft_strcmp((const char *)cur_node->name, "object"))
				sub_xml_read_object(map->obj, cur_node->children);
			else if (!ft_strcmp((const char *)cur_node->name, "camera"))
				sub_xml_read_camera(map->camera, cur_node->children);
		}
		recursive_parser(cur_node->children, map);
		cur_node = cur_node->next;
	}
}

void		sub_parser_xml(t_fullmap *map, xmlDoc *doc)
{
	xmlNode *root_element;

	if (doc == NULL)
		ft_exit("Parser failed to open file\n");
	printf("Starting parsing of %s\n", map->mapfile_pathname);
	root_element = xmlDocGetRootElement(doc);
	recursive_parser(root_element, map);
	xmlFreeDoc(doc);
	xmlCleanupParser();
	map->target_cam = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_parser_xml.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 17:28:34 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/27 17:21:08 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	recursive_parser(xmlNode *node, t_fullmap *map)
{
	xmlNode *cur_node;

	cur_node = node;
	while (cur_node)
	{
		if (cur_node->type == XML_ELEMENT_NODE)
		{
			if (!ft_strcmp((const char *)cur_node->name, "resolution"))
				map->res = ft_xml_rd_res((char *)xmlNodeGetContent(cur_node));
			else if (!ft_strcmp((const char *)cur_node->name, "lights"))
				map->light = sub_malloc_lights(map, cur_node->children);
			else if (!ft_strcmp((const char *)cur_node->name, "objects"))
				map->obj = sub_malloc_objects(map, cur_node->children);
			else if (!ft_strcmp((const char *)cur_node->name, "light"))
				sub_xml_read_light(map->light, cur_node->children);
			else if (!ft_strcmp((const char *)cur_node->name, "object"))
				sub_xml_read_object(map->obj, cur_node->children);
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
}

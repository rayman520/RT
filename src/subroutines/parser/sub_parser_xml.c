/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_parser_xml.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 17:28:34 by cpierre           #+#    #+#             */
/*   Updated: 2018/03/06 16:54:09 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		default_options(t_fullmap *map)
{
	map->res = (t_2dint){1280, 800};
	map->editres = (t_2dint){1280, 800};
	map->fps = (t_2dint){30, 60};
	map->maxdepth = 3;
	map->fov = 30;
	map->color_saturation = 1.5;
	map->amb_coef = 0;
	map->filter = 0;
	map->bias = 0.00001;
}

static void		options_parser2(t_fullmap *map, const char *name,
										xmlNode *cur_node)
{
	if (!ft_strcmp(name, "resolution"))
		map->res = ft_xml_rd_res(xmlngc(cur_node));
	else if (!ft_strcmp(name, "editor_res"))
		map->editres = ft_xml_ed_res(xmlngc(cur_node));
	else if (!ft_strcmp(name, "editor_fps_low"))
		map->fps.x = ft_atoi(xmlngc(cur_node));
	else if (!ft_strcmp(name, "editor_fps_high"))
		map->fps.y = ft_atoi(xmlngc(cur_node));
	else if (!ft_strcmp(name, "fov"))
		map->fov = ft_atoi(xmlngc(cur_node));
	else if (!ft_strcmp(name, "ambiant_occ"))
		map->coef = (double)ft_atof(xmlngc(cur_node));
	else if (!ft_strcmp(name, "ambiant_light"))
		map->amb_coef = (double)ft_atof(xmlngc(cur_node));
	else if (!ft_strcmp(name, "maxdepth"))
		map->maxdepth = ft_atoi(xmlngc(cur_node));
	else if (!ft_strcmp(name, "color_saturation"))
		map->color_saturation = (double)ft_atof(xmlngc(cur_node));
	else if (!ft_strcmp(name, "filter"))
		map->filter = sub_read_filter(xmlngc(cur_node));
	else if (!ft_strcmp(name, "bias"))
		map->bias = (double)ft_atof(xmlngc(cur_node));
}

static void		options_parser(xmlNode *node, t_fullmap *map)
{
	xmlNode *cur_node;

	default_options(map);
	cur_node = node;
	while (cur_node)
	{
		if (cur_node->type == XML_ELEMENT_NODE)
			options_parser2(map, (t_cstr)cur_node->name, cur_node);
		cur_node = cur_node->next;
	}
}

static void		recursive_parser(xmlNode *node, t_fullmap *map)
{
	xmlNode		*cur_node;
	static int	went_through_options = 0;

	cur_node = node;
	while (cur_node)
	{
		if (cur_node->type == XML_ELEMENT_NODE)
		{
			if (!ft_strcmp((const char *)cur_node->name, "options"))
			{
				went_through_options = 1;
				options_parser(cur_node->children, map);
			}
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
	if (!went_through_options)
		ft_exit("i can't belive you've done this");
}

void			sub_parser_xml(t_fullmap *map, xmlDoc *doc)
{
	xmlNode *root_element;

	if (doc == NULL)
		ft_exit("Parser failed to open file\n");
	root_element = xmlDocGetRootElement(doc);
	map->light = NULL;
	map->obj = NULL;
	map->camera = NULL;
	recursive_parser(root_element, map);
	if (map->light == NULL || map->obj == NULL || map->camera == NULL)
		ft_exit("Parser failed. get riped.");
	xmlFreeDoc(doc);
	xmlCleanupParser();
	map->target_cam = 0;
}

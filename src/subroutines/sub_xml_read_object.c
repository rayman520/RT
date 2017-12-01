/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_xml_read_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:19:42 by cpierre           #+#    #+#             */
/*   Updated: 2017/12/01 14:23:11 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_obj_t	read_obj_type(t_str str)
{
	ft_strupcase(str);
	if (!ft_strcmp(str, "SPHERE"))
	{
		printf("object type consedered as sphere\n");
		return (SPHERE);
	}
	else
	{
		printf("Object type not recognized, setting to sphere\n");
		return (SPHERE);
	}
}

void			sub_xml_read_object(t_object *obj, xmlNode *node)
{
	static int o_nb = 0;

	printf("Reading object %d\n", o_nb + 1);
	while (node)
	{
		if (!ft_strcmp((const char *)node->name, "position"))
			obj[o_nb].pos = sub_read_pos((char *)xmlNodeGetContent(node));
		if (!ft_strcmp((const char *)node->name, "type"))
			obj[o_nb].type = read_obj_type((char *)xmlNodeGetContent(node));
		if (!ft_strcmp((const char *)node->name, "radius"))
		{
			obj[o_nb].radius = (double)ft_atof((char *)xmlNodeGetContent(node));
			printf("Radius set to: %f\n", obj[o_nb].radius);
		}
		if (!ft_strcmp((const char *)node->name, "color"))
		{
			obj[o_nb].color = sub_read_hex((char *)xmlNodeGetContent(node));
			printf("Color set to: %x\n", obj[o_nb].color);
		}
		if (!ft_strcmp((const char *)node->name, "texture"))
			obj[o_nb].texture = sub_read_texture((t_str)xmlNodeGetContent(node));
		node = node->next;
	}
	o_nb++;
}

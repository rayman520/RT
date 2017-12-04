/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_xml_read_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 14:59:06 by nthibaud          #+#    #+#             */
/*   Updated: 2017/12/04 15:30:08 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_xml_read_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:19:42 by cpierre           #+#    #+#             */
/*   Updated: 2017/12/04 13:21:41 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

	static t_obj_t	read_obj_type(t_str str)
	{
		ft_strupcase(str);
		printf("Object type considered as %s\n", str);
		if (ft_is_any_string(str, 2, "SPHERE", "SPH"))
			return (SPHERE);
		else if (ft_is_any_string(str, 2, "CONE", "CON"))
			return (CONE);
		else if (ft_is_any_string(str, 3, "CYLINDER", "CYLINDRE", "CYL"))
			return (CYLINDER);
		else if (ft_is_any_string(str, 3, "PLANE", "PLAN", "PLA"))
		return (PLANE);
	else if (ft_is_any_string(str, 2, "DISC", "DISK", "DIS"))
		return (DISK);
	else
	{
		printf("Object type not recognized, setting to sphere\n");
		return (SPHERE);
	}
}

static t_obj_t	read_obj_material(t_str str)
	{
		ft_strupcase(str);
		printf("Object type considered as %s\n", str);
		if (ft_is_any_string(str, 2, "DEFAULT", "DEF"))
			return (DEFAULT);
		else if (ft_is_any_string(str, 2, "REFLECTIVE", "REFL"))
			return (REFLECTIVE);
		else if (ft_is_any_string(str, 2, "REFRACTIVE", "REFR"))
			return (REFRAFLECTIVE);
		else
		{
			printf("Object material not recognized, setting to default\n");
			return (DEFAULT);
		}
}

void			sub_xml_read_object(t_object *obj, xmlNode *node)
{
	static int o_nb = 0;

	printf("Reading object %d\n", o_nb + 1);
	obj[o_nb].texture = NULL;
	while (node)
	{
		if (!ft_strcmp((const char *)node->name, "position"))
			obj[o_nb].pos = sub_read_pos((char *)xmlNodeGetContent(node));
		if (!ft_strcmp((const char *)node->name, "direction"))
			obj[o_nb].dir = sub_read_pos((char *)xmlNodeGetContent(node));
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
		if (!ft_strcmp((const char *)node->name, "material"))
			obj[o_nb].material = read_obj_material((t_str)xmlNodeGetContent(node));
		if (!ft_strcmp((const char *)node->name, "reflection"))
			obj[o_nb].reflection = (double)ft_atof((t_str)xmlNodeGetContent(node));
		if (!ft_strcmp((const char *)node->name, "refraction"))
			obj[o_nb].refraction = (double)ft_atof((t_str)xmlNodeGetContent(node));
		if (!ft_strcmp((const char *)node->name, "albedo"))
			obj[o_nb].albedo = (double)ft_atof((t_str)xmlNodeGetContent(node));
		node = node->next;
	}
	o_nb++;
}

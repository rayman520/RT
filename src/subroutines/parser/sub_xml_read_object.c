/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_xml_read_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:19:42 by cpierre           #+#    #+#             */
/*   Updated: 2018/03/13 19:18:06 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_obj_t	read_obj_type(t_str str)
{
	ft_strupcase(str);
	if (ft_is_any_string(str, 2, "CONE", "CON"))
		return (CONE);
	else if (ft_is_any_string(str, 3, "CYLINDER", "CYLINDRE", "CYL"))
		return (CYLINDER);
	else if (ft_is_any_string(str, 3, "PLANE", "PLAN", "PLA"))
		return (PLANE);
	else if (ft_is_any_string(str, 2, "DISC", "DISK", "DIS"))
		return (DISK);
	else if (ft_is_any_string(str, 2, "TRIANGLE", "TRI"))
		return (TRIANGLE);
	else if (ft_is_any_string(str, 2, "PARABOLOID", "PARA"))
		return (PARABOLOID);
	else if (ft_is_any_string(str, 2, "HYPERBOLOID", "HYP"))
		return (HYPERBOLOID);
	else
		return (SPHERE);
}

static t_obj_t	read_obj_textype_material(t_str str)
{
	ft_strupcase(str);
	if (ft_is_any_string(str, 2, "DEFAULT", "DEF"))
		return (DEFAULT);
	else if (ft_is_any_string(str, 1, "CHESS"))
		return (CHESS);
	else if (ft_is_any_string(str, 1, "PERLIN"))
		return (PERLIN);
	else if (ft_is_any_string(str, 1, "MARBLE"))
		return (MARBLE);
	else if (ft_is_any_string(str, 2, "REFLECTIVE", "REFL"))
		return (REFLECTIVE);
	else if (ft_is_any_string(str, 2, "REFRACTIVE", "REFR"))
		return (REFRAFLECTIVE);
	else
		return (DEFAULT);
}

static void		sub_xml_read_object3(t_object *obj, const char *name, int o_nb,
										xmlNode *node)
{
	if (!ft_strcmp(name, "refraction"))
		obj[o_nb].refraction = (double)ft_atof(xmlngc(node));
	else if (!ft_strcmp(name, "albedo"))
		obj[o_nb].albedo = (double)ft_atof(xmlngc(node));
	else if (!ft_strcmp(name, "refracoef"))
		obj[o_nb].refracoef = (double)ft_atof(xmlngc(node));
	else if (!ft_strcmp(name, "negative"))
		obj[o_nb].negative = (ft_is_any_string(xmlngc(node), 1, "YES")
			? YES : NO);
	else if (!ft_strcmp(name, "min"))
		obj[o_nb].min = sub_read_pos(xmlngc(node));
	else if (!ft_strcmp(name, "max"))
		obj[o_nb].max = sub_read_pos(xmlngc(node));
	else if (!ft_strcmp(name, "pa"))
		obj[o_nb].pa = sub_read_pos(xmlngc(node));
	else if (!ft_strcmp(name, "pb"))
		obj[o_nb].pb = sub_read_pos(xmlngc(node));
	else if (!ft_strcmp(name, "pc"))
		obj[o_nb].pc = sub_read_pos(xmlngc(node));
	else if (!ft_strcmp(name, "pd"))
		obj[o_nb].pd = sub_read_pos(xmlngc(node));
	else if (!ft_strcmp(name, "bump"))
		obj[o_nb].bump = (double)ft_atof(xmlngc(node));
}

static void		sub_xml_read_object2(t_object *obj, const char *name, int o_nb,
										xmlNode *node)
{
	if (!ft_strcmp(name, "position"))
		obj[o_nb].pos = sub_read_pos(xmlngc(node));
	else if (!ft_strcmp(name, "direction"))
		obj[o_nb].dir = sub_read_pos(xmlngc(node));
	else if (!ft_strcmp(name, "type"))
		obj[o_nb].type = read_obj_type(xmlngc(node));
	else if (!ft_strcmp(name, "textype"))
		obj[o_nb].texture_type = read_obj_textype_material(xmlngc(node));
	else if (!ft_strcmp(name, "radius"))
		obj[o_nb].radius = (double)ft_atof(xmlngc(node));
	else if (!ft_strcmp(name, "color"))
		obj[o_nb].color = sub_read_hex(xmlngc(node));
	else if (!ft_strcmp(name, "specsize"))
		obj[o_nb].spec_size = (double)ft_atof(xmlngc(node));
	else if (!ft_strcmp(name, "specpower"))
		obj[o_nb].spec_power = (double)ft_atof(xmlngc(node));
	else if (!ft_strcmp(name, "texture"))
		obj[o_nb].texture = sub_read_texture(xmlngc(node));
	else if (!ft_strcmp(name, "material"))
		obj[o_nb].material = read_obj_textype_material(xmlngc(node));
	else if (!ft_strcmp(name, "reflection"))
		obj[o_nb].reflection = (double)ft_atof(xmlngc(node));
	else
		sub_xml_read_object3(obj, name, o_nb, node);
}

void			sub_xml_read_object(t_object *obj, xmlNode *node)
{
	static int o_nb = 0;

	if (obj != NULL)
	{
		default_object(obj, o_nb);
		while (node)
		{
			ft_check_tag_ception((const char *)node->name);
			sub_xml_read_object2(obj, (t_cstr)node->name, o_nb, node);
			node = node->next;
		}
		o_nb++;
	}
}

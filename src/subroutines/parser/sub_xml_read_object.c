/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_xml_read_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:19:42 by cpierre           #+#    #+#             */
/*   Updated: 2018/02/02 16:13:03 by nthibaud         ###   ########.fr       */
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
		else if (ft_is_any_string(str, 2, "TRIANGLE", "TRI"))
			return (TRIANGLE);
		else if (ft_is_any_string(str, 2, "QUADRANGLE", "QUAD"))
			return (QUADRANGLE);
		else if (ft_is_any_string(str, 2, "PARALLELOGRAM", "PLGM"))
			return (PARALLELOGRAM);
		else if (ft_is_any_string(str, 2, "PYRAMID", "PYR"))
			return (PYRAMID);
		else if (ft_is_any_string(str, 2, "ELLIPSOID", "ELI"))
			return (ELLIPSOID);
		else if (ft_is_any_string(str, 2, "PARABOLOID", "PARA"))
			return (PARABOLOID);
		else if (ft_is_any_string(str, 2, "HYPERBOLOID", "HYP"))
			return (HYPERBOLOID);
	else
	{
		printf("Object type not recognized, setting to sphere\n");
		return (SPHERE);
	}
}

static t_obj_t	read_obj_textype(t_str str)
{
	ft_strupcase(str);
	printf("Object texture considered as %s\n", str);
	if (ft_is_any_string(str, 2, "DEFAULT", "DEF"))
		return (DEFAULT);
	else if (ft_is_any_string(str, 1, "CHESS"))
		return (CHESS);
	else if (ft_is_any_string(str, 1, "PERLIN"))
		return (PERLIN);
	else if (ft_is_any_string(str, 1, "MARBLE"))
		return (MARBLE);
else
{
	printf("Object texture not recognized, setting to default\n");
	return (DEFAULT);
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

static void		default_object(t_object *obj, int o_nb)
{
	obj[o_nb].type = SPHERE;
	obj[o_nb].texture = NULL;
	obj[o_nb].material = DEFAULT;
	obj[o_nb].texture_type = DEFAULT;
	obj[o_nb].bump = 0.0;
	obj[o_nb].color = 0xFFFFFF;
	obj[o_nb].spec_size = 20.0;
	obj[o_nb].spec_power = 0;
	obj[o_nb].albedo = 0.18;
	obj[o_nb].radius = 1.0;
	obj[o_nb].reflection = 0.5;
	obj[o_nb].refraction = 1.0;
	obj[o_nb].refracoef = 1.0;
	obj[o_nb].negative = NO;
	obj[o_nb].pos = (t_3d_double){0,0,0};
	obj[o_nb].dir = (t_3d_double){0,0,1};
}

void			sub_xml_read_object(t_object *obj, xmlNode *node)
{
	static int o_nb = 0;

	default_object(obj, o_nb);
	printf("Reading object %d\n", o_nb + 1);
	while (node)
	{
		if (!ft_strcmp((const char *)node->name, "position"))
			obj[o_nb].pos = sub_read_pos((char *)xmlNodeGetContent(node));
		if (!ft_strcmp((const char *)node->name, "direction"))
			obj[o_nb].dir = sub_read_pos((char *)xmlNodeGetContent(node));
		if (!ft_strcmp((const char *)node->name, "type"))
			obj[o_nb].type = read_obj_type((char *)xmlNodeGetContent(node));
		if (!ft_strcmp((const char *)node->name, "textype"))
			obj[o_nb].texture_type = read_obj_textype((char *)xmlNodeGetContent(node));
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
		if (!ft_strcmp((const char *)node->name, "specsize"))
			obj[o_nb].spec_size = (double)ft_atof((t_str)xmlNodeGetContent(node));
		if (!ft_strcmp((const char *)node->name, "specpower"))
			obj[o_nb].spec_power = (double)ft_atof((t_str)xmlNodeGetContent(node));
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
		if (!ft_strcmp((const char *)node->name, "refracoef"))
			obj[o_nb].refracoef = (double)ft_atof((t_str)xmlNodeGetContent(node));
		if (!ft_strcmp((const char *)node->name, "negative"))
			obj[o_nb].negative = (ft_is_any_string((char *)xmlNodeGetContent(node), 1, "YES") ? YES : NO);
		if (!ft_strcmp((const char *)node->name, "min"))
			obj[o_nb].min = sub_read_pos((char *)xmlNodeGetContent(node));
		if (!ft_strcmp((const char *)node->name, "max"))
			obj[o_nb].max = sub_read_pos((char *)xmlNodeGetContent(node));
		if (!ft_strcmp((const char *)node->name, "pa"))
			obj[o_nb].pa = sub_read_pos((char *)xmlNodeGetContent(node));
		if (!ft_strcmp((const char *)node->name, "pb"))
			obj[o_nb].pb = sub_read_pos((char *)xmlNodeGetContent(node));
		if (!ft_strcmp((const char *)node->name, "pc"))
			obj[o_nb].pc = sub_read_pos((char *)xmlNodeGetContent(node));
		if (!ft_strcmp((const char *)node->name, "pd"))
			obj[o_nb].pd = sub_read_pos((char *)xmlNodeGetContent(node));
		if (!ft_strcmp((const char *)node->name, "bump"))
			obj[o_nb].bump = (double)ft_atof((t_str)xmlNodeGetContent(node));
		node = node->next;
	}
	o_nb++;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_xml_read_camera.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 17:28:23 by cpierre           #+#    #+#             */
/*   Updated: 2018/03/12 14:27:19 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	default_camera(t_vect *cam, int c_nb)
{
	cam[c_nb].pos = (t_3d_double){-5, 0, 0};
	cam[c_nb].dir = (t_3d_double){1, 0, 0};
}

void		sub_xml_read_camera(t_vect *cam, xmlNode *node)
{
	static int c_nb = 0;

	if (cam != NULL)
	{
		default_camera(cam, c_nb);
		while (node)
		{
			if (!ft_strcmp((const char *)node->name, "position"))
				cam[c_nb].pos = sub_read_pos(xmlngc(node));
			if (!ft_strcmp((const char *)node->name, "direction"))
				cam[c_nb].dir = sub_read_dir(xmlngc(node));
			if (!ft_strcmp((const char *)node->name, "camera"))
				ft_exit("camera-ception");
			node = node->next;
		}
		c_nb++;
	}
}

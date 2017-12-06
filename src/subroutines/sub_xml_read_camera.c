/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_xml_read_camera.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 17:28:23 by cpierre           #+#    #+#             */
/*   Updated: 2017/12/06 12:26:22 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	default_camera(t_vect *cam, int c_nb)
{
	cam[c_nb].pos = (t_3d_double){-5,0,0};
	cam[c_nb].dir = (t_3d_double){1,0,0};
}

void		sub_xml_read_camera(t_vect *cam, xmlNode *node)
{
	static int c_nb = 0;

	default_camera(cam, c_nb);
	printf("Reading camera %d\n", c_nb + 1);
	while (node)
	{
		if (!ft_strcmp((const char *)node->name, "position"))
			cam[c_nb].pos = sub_read_pos((char *)xmlNodeGetContent(node));
		if (!ft_strcmp((const char *)node->name, "direction"))
			cam[c_nb].dir = sub_read_dir((char *)xmlNodeGetContent(node));
		node = node->next;
	}
	c_nb++;
}

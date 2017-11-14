/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_xml_read_camera.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 17:28:23 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/29 16:42:38 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	sub_xml_read_camera(t_vect *cam, xmlNode *node)
{
	static int c_nb = 0;

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

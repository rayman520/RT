/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_xml_read_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:01:34 by cpierre           #+#    #+#             */
/*   Updated: 2018/02/17 20:13:56 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	default_light(t_light *light, int l_nb)
{
	light[l_nb].pos = (t_3d_double){-2,2,2};
	light[l_nb].color = (t_3d_double){255,255,255};
	light[l_nb].pow = 10;
	light[l_nb].intensity = 0.5;
}

void		sub_xml_read_light(t_light *light, xmlNode *node)
{
	static int l_nb = 0;

	if (light != NULL)
	{
		default_light(light, l_nb);
		printf("Reading light %d\n", l_nb + 1);
		while (node)
		{
			if (!ft_strcmp((const char *)node->name, "position"))
				light[l_nb].pos = sub_read_pos((char *)xmlNodeGetContent(node));
				if (!ft_strcmp((const char *)node->name, "power"))
					printf("Light power set to %f\n",
					light[l_nb].pow = sub_read_double((char *)xmlNodeGetContent(node)));
				if (!ft_strcmp((const char *)node->name, "intensity"))
					light[l_nb].intensity = (double)ft_atof((t_str)xmlNodeGetContent(node));
				if (!ft_strcmp((const char *)node->name, "color"))
					light[l_nb].color = sub_read_3d_double((t_str)xmlNodeGetContent(node));
				if (!ft_strcmp((const char *)node->name, "bias"))
				light[l_nb].bias = (double)ft_atof((t_str)xmlNodeGetContent(node));
			node = node->next;
		}
	l_nb++;
}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_xml_read_light.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:01:34 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/28 17:55:05 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	sub_xml_read_light(t_light *light, xmlNode *node)
{
	static int l_nb = 0;

	printf("Reading light %d\n", l_nb + 1);
	while (node)
	{
		if (!ft_strcmp((const char *)node->name, "position"))
			light[l_nb].pos = sub_read_pos((char *)xmlNodeGetContent(node));
		if (!ft_strcmp((const char *)node->name, "power"))
			printf("Light power set to %f\n",
			light[l_nb].pow = sub_read_double((char *)xmlNodeGetContent(node)));
		node = node->next;
	}
	l_nb++;
}

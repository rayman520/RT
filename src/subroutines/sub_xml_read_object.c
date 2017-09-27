/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_xml_read_objects.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 17:19:42 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/27 17:22:42 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	sub_xml_read_object(t_object *obj, xmlNode *node)
{
	static int o_nb = 0;

	printf("Reading object %d\n", o_nb + 1);
	while (node)
	{
		if (!ft_strcmp((const char *)node->name, "position"))
			obj[o_nb].pos = sub_read_pos((char *)xmlNodeGetContent(node));
		node = node->next;
	}
	o_nb++;
}

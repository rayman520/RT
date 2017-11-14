/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_create_xml.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 17:48:39 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/29 12:47:31 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	sub_create_xml(int fd)
{
	dprintf(fd, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
	dprintf(fd, "<map>\n");
	dprintf(fd, "\t<options>\n");
	dprintf(fd, "\t\t<resolution>640x480</resolution>\n");
	dprintf(fd, "\t</options>\n");
	dprintf(fd, "\t<cameras>\n");
	dprintf(fd, "\t\t<camera>\n");
	dprintf(fd, "\t\t\t<position>-1.0,0,0</position>\n");
	dprintf(fd, "\t\t\t<direction>1,0,0</direction>\n");
	dprintf(fd, "\t\t</camera>\n");
	dprintf(fd, "\t</cameras>\n");
	dprintf(fd, "\t<lights>\n");
	dprintf(fd, "\t\t<light>\n");
	dprintf(fd, "\t\t\t<position>0,3,0</position>\n");
	dprintf(fd, "\t\t\t<power>10</power>\n");
	dprintf(fd, "\t\t</light>\n");
	dprintf(fd, "\t</lights>\n");
	dprintf(fd, "\t<objects>\n");
	dprintf(fd, "\t\t<object>\n");
	dprintf(fd, "\t\t\t<type>sphere</type>\n");
	dprintf(fd, "\t\t\t<position>2,0,-1</position>\n");
	dprintf(fd, "\t\t</object>\n");
	dprintf(fd, "\t</objects>\n");
	dprintf(fd, "</map>\n");
}

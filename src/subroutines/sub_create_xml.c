/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_create_xml.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 17:48:39 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/27 18:02:32 by cpierre          ###   ########.fr       */
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
	dprintf(fd, "\t<lights>\n");
	dprintf(fd, "\t\t<light>\n");
	dprintf(fd, "\t\t\t<position>6.2,-8,3.96</position>\n");
	dprintf(fd, "\t\t\t<power>10.92</power>\n");
	dprintf(fd, "\t\t</light>\n");
	dprintf(fd, "\t</lights>\n");
	dprintf(fd, "\t<objects>\n");
	dprintf(fd, "\t\t<object>\n");
	dprintf(fd, "\t\t\t<position>2,7.666,-42.5</position>\n");
	dprintf(fd, "\t\t</object>\n");
	dprintf(fd, "\t</objects>\n");
	dprintf(fd, "</map>\n");
}

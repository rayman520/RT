/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_texture_cone_cyl.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 16:54:56 by cpierre           #+#    #+#             */
/*   Updated: 2018/01/10 11:59:33 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ui				sub_texture_cone_cyl(t_hit hit)
{
	double 	phi;
	double 	theta;

	theta = atan2((double)(hit.pos.y - hit.obj->pos.y), (double)(hit.pos.x - hit.obj->pos.x));
	while (theta > 2 * M_PI)
		theta -= 2 * M_PI;
	phi = (int)(ft_flabs(hit.pos.z) * 100) % (hit.obj->texture->h / 4);
	theta = (theta / (double)(2 * M_PI)) * (double)hit.obj->texture->w / (double)4;
	printf("%d,%d\n",(int)theta,(int)phi);
	return (getpixel(hit.obj->texture, (int)theta + 1, (int)phi + 1));
}

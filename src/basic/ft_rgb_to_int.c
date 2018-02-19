/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 16:44:16 by cpierre           #+#    #+#             */
/*   Updated: 2018/02/19 17:24:04 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ui	ft_rgb_to_int(t_3d_double color)
{
	t_ui	out;

	if (color.z > 255)
		color.z = 255;
	else if (color.z < 0)
		color.z = 0;
	if (color.y > 255)
		color.y = 255;
	else if (color.y < 0)
		color.y = 0;
	if (color.x > 255)
		color.x = 255;
	else if (color.x < 0)
		color.x = 0;
	out = (t_ui)color.z * 0x010000 + (t_ui)color.y * 0x000100 + (t_ui)color.x;
	return (out);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_3d_to_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:50:13 by nthibaud          #+#    #+#             */
/*   Updated: 2018/02/19 17:22:57 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ui	ft_double_3d_to_int(t_3d_double color)
{
	t_ui new_color;

	if (color.x > 255)
		color.x = 255;
	else if (color.x < 0)
		color.x = 0;
	if (color.y > 255)
		color.y = 255;
	else if (color.y < 0)
		color.y = 0;
	if (color.z > 255)
		color.z = 255;
	else if (color.z < 0)
		color.z = 0;
	new_color = (t_ui)color.x * 0x010000 +
		(t_ui)color.y * 0x000100 + (t_ui)color.z;
	return (new_color);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_double_3d.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 16:51:03 by nthibaud          #+#    #+#             */
/*   Updated: 2017/11/29 16:51:44 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_3d_double	ft_int_to_double_3d(t_ui color)
{
	t_3d_double new_color;

	new_color.x = (double)((color & 0xFF0000) >> 16);
	new_color.y = (double)((color & 0x00FF00) >> 8);
	new_color.z = (double)(color & 0x0000FF);
	return (new_color);
}

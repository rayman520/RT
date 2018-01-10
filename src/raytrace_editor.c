/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_editor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:24:21 by cpierre           #+#    #+#             */
/*   Updated: 2018/01/08 15:49:32 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ui			raytrace_editor(t_fullmap *map, t_vect ray)
{
	t_3d_double	color;

	map->coef = 0.5;
	color = raytrace_loop(map, ray, 0);
	ft_rt_filter(map, &color);
	return ((unsigned int)ft_double_3d_to_int(color));
}

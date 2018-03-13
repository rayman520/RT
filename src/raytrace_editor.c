/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_editor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:24:21 by cpierre           #+#    #+#             */
/*   Updated: 2018/03/13 14:52:18 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_ui			raytrace_editor(t_fullmap *map, t_vect ray)
{
	t_3d_double	color;

	color = raytrace_loop(map, ray, 0);
	if (map->filter != 0)
		ft_rt_filter(map, &color);
	return ((unsigned int)ft_double_3d_to_int(color));
}

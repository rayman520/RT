/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 16:06:27 by cpierre           #+#    #+#             */
/*   Updated: 2018/02/19 17:19:15 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	default_object(t_object *obj, int o_nb)
{
	obj[o_nb].type = SPHERE;
	obj[o_nb].texture = NULL;
	obj[o_nb].material = DEFAULT;
	obj[o_nb].texture_type = DEFAULT;
	obj[o_nb].bump = 0.0;
	obj[o_nb].color = 0xFFFFFF;
	obj[o_nb].spec_size = 20.0;
	obj[o_nb].spec_power = 0;
	obj[o_nb].albedo = 0.18;
	obj[o_nb].radius = 1.0;
	obj[o_nb].reflection = 0.5;
	obj[o_nb].refraction = 1.0;
	obj[o_nb].refracoef = 1.0;
	obj[o_nb].negative = NO;
	obj[o_nb].pos = (t_3d_double){0, 0, 0};
	obj[o_nb].dir = (t_3d_double){0, 0, 1};
	obj[o_nb].min = (t_3d_double){DBMIN, DBMIN, DBMIN};
	obj[o_nb].max = (t_3d_double){DBMAX, DBMAX, DBMAX};
}

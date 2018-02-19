/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_div_by_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:26:06 by nthibaud          #+#    #+#             */
/*   Updated: 2018/02/19 17:09:08 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_3d_double	v_div_by_nb(t_3d_double v, double nb)
{
	t_3d_double c;

	c.x = (double)v.x / nb;
	c.y = (double)v.y / nb;
	c.z = (double)v.z / nb;
	return (c);
}

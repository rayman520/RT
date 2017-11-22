/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_div_by_v.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:26:12 by nthibaud          #+#    #+#             */
/*   Updated: 2017/11/22 11:26:14 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt.h"

t_3d_double	v_div_by_vv(t_3d_double a, t_3d_double b)
{
	t_3d_double c;
	c.x = a.x / b.x;
	c.y = a.y / b.y;
	c.z = a.z / b.z;
	return (c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_mult_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:30:10 by nthibaud          #+#    #+#             */
/*   Updated: 2017/11/22 11:38:16 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_3d_double	m4_mult_v(double **m, t_3d_double v)
{
	double	px;
	double	py;
	double	pz;

	px = v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0] + 1 * m[3][0];
	py = v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1] + 1 * m[3][1];
	pz = v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2] + 1 * m[3][2];
	v.x = px;
	v.y = py;
	v.z = pz;
	return (v);
}

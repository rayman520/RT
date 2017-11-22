/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:25:06 by nthibaud          #+#    #+#             */
/*   Updated: 2017/11/22 11:54:36 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	m4_row_fill(double **m, t_3d_double v, int row, double last_col)
{
	m[row][0] = v.x;
	m[row][1] = v.y;
	m[row][2] = v.z;
	m[row][3] = last_col;
}

void	m4_fill(double **m, t_m_rows m_rows)
{
	m4_row_fill(m, m_rows.x_row, 0, 0);
	m4_row_fill(m, m_rows.y_row, 1, 0);
	m4_row_fill(m, m_rows.z_row, 2, 0);
	m4_row_fill(m, m_rows.w_row, 3, 1);
}

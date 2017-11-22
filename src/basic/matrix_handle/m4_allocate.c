/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:28:27 by nthibaud          #+#    #+#             */
/*   Updated: 2017/11/22 12:06:43 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	**m4_allocate(void)
{
	double	**m;
	int		i;

	i = 0;
	m = (double **)malloc(sizeof(double *) * 4 + 1);
	m[4] = NULL;
	while (i < 4)
	{
		m[i] = (double *)malloc(sizeof(double) * 4);
		i++;
	}
	return (m);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doubleswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 13:33:27 by cpierre           #+#    #+#             */
/*   Updated: 2018/02/19 17:22:50 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_doubleswap(double *d1, double *d2)
{
	double	tmp;

	tmp = *d1;
	*d1 = *d2;
	*d2 = tmp;
}

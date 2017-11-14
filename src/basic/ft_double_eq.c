/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_eq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:59:01 by cpierre           #+#    #+#             */
/*   Updated: 2017/10/12 17:02:41 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	ft_double_eq(double nb1, double nb2, double t)
{
	if (nb1 < nb2 - t)
		return (0);
	else if (nb1 > nb2 + t)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:42:27 by cpierre           #+#    #+#             */
/*   Updated: 2017/12/05 17:43:08 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	ft_flabs(float nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}
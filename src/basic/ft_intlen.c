/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:30:37 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/27 16:30:58 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

size_t	ft_uintlen(unsigned int nb)
{
	if (nb > 9)
		return (ft_uintlen(nb / 10) + ft_uintlen(nb % 10));
	return (1);
}

size_t	ft_intlen(int nb)
{
	if (nb < 0)
		return (ft_uintlen((unsigned int)-nb) + 1);
	return (ft_uintlen((unsigned int)nb));
}

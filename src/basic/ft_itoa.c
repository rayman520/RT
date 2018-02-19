/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:27:25 by cpierre           #+#    #+#             */
/*   Updated: 2018/02/19 17:23:19 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_str			ft_itoa(int n)
{
	t_str			str;
	int				i;
	short			is_neg;
	unsigned int	nbr;

	i = (int)ft_intlen(n) - 1;
	if (!(str = (char *)malloc(sizeof(char) * (unsigned int)i + 2)))
		return (0);
	nbr = (unsigned int)n;
	is_neg = (short)i + 1;
	if (n < 0)
	{
		nbr = (unsigned int)-n;
		str[0] = '-';
	}
	while (i - (n < 0) >= 0)
	{
		str[i] = '0' + (nbr % 10);
		nbr /= 10;
		i--;
	}
	str[is_neg] = '\0';
	return (str);
}

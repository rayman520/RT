/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:20:53 by cpierre           #+#    #+#             */
/*   Updated: 2017/12/01 14:17:57 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int		get_sign(t_str str)
{
	int		sign;
	t_ui	i;

	i = 0;
	sign = 1;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		else if (str[i] == '+')
			sign *= 1;
		++i;
	}
	if (!ft_isnbr(str[i]))
		return (0);
	return (sign);
}

static float	atof_pt2(t_str str, float nb1, float nb2)
{
	t_ui i;

	i = 0;
	while (ft_isspace(str[i]))
		++i;
	while (ft_isnbr(str[i]))
	{
		++i;
		nb2 = nb2 / 10;
	}
	return (nb1 + nb2);
}

float			ft_atof(t_str str)
{
	t_ui	i;
	int		sign;
	int		nb1;
	int		nb2;

	i = 0;
	while (ft_isspace(str[i]))
		++i;
	if (!(sign = get_sign(&str[i])))
		return (0);
	while (!ft_isnbr(str[i]))
		++i;
	nb1 = ft_atoi(&str[i]);
	while (ft_isnbr(str[i]))
		++i;
	if (str[i] != '.')
		return ((float)(sign * nb1));
	++i;
	nb2 = ft_atoi(&str[i]);
	return (sign * atof_pt2(&str[i], (float)nb1, (float)nb2));
}

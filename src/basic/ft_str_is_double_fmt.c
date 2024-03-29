/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_double_fmt.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 18:38:57 by cpierre           #+#    #+#             */
/*   Updated: 2018/03/13 20:18:46 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	ft_str_is_double_fmt(t_str str)
{
	while (str && *str)
	{
		if (!(ft_isnbr(*str) || *str == '.' || *str == ',' || *str == '-'))
			return (0);
		str++;
	}
	return (1);
}

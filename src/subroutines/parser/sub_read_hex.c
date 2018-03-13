/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_read_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 11:36:52 by cpierre           #+#    #+#             */
/*   Updated: 2018/03/13 20:50:48 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

unsigned int	sub_read_hex(t_str str)
{
	int				i;
	unsigned int	out;

	i = 0;
	out = 0;
	if (!str || ft_strlen(str) < 1 || str[i++] != '0')
		return (out);
	if (!(str[i] == 'x' || str[i] == 'X'))
		return (out);
	i++;
	while ((str[i] >= '0' && str[i] <= '9') ||
		(str[i] >= 'a' && str[i] <= 'f') || (str[i] >= 'A' && str[i] <= 'F'))
	{
		out *= 16;
		if (str[i] >= '0' && str[i] <= '9')
			out += (t_ui)(str[i] - '0');
		else if (str[i] >= 'a' && str[i] <= 'f')
			out += (t_ui)(str[i] - 'a' + 10);
		else
			out += (t_ui)(str[i] - 'A' + 10);
		i++;
	}
	return (out);
}

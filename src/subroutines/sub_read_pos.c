/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_read_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:12:53 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/27 18:01:27 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double	atodouble(t_str str)
{
	double	out;

	out = 0;
	while (*str >= '0' && *str <= '9')
	{
		out = out * 10 + (*str - '0');
		str++;
	}
	return (out);
}

double			sub_read_double(t_str str)
{
	double	big;
	double	small;
	int		i;

	i = 0;
	if (str[0] == '-')
		big = atodouble(&str[++i]) * -1;
	else
		big = atodouble(&str[i]);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == 0 || str[i] == ',')
		return (big);
	else if (str[i] == '.')
	{
		small = atodouble(&str[i + 1]);
		while (small > 1)
			small /= 10.0;
		return (big + small);
	}
	else
	{
		printf("Invalid double format given, setting to pos = 0\n");
		return ((double)0);
	}
}

t_3d_double		sub_read_pos(t_str str)
{
	t_3d_double	out;
	int			i;

	if (str == NULL)
	{
		printf("position unknown, set it to default: 0,0,0\n");
		return ((t_3d_double){0, 0, 0});
	}
	out.x = sub_read_double(str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == ',')
			break ;
	}
	out.y = sub_read_double(&str[++i]);
	while (str[i])
	{
		if (str[i] == ',')
			break ;
		i++;
	}
	out.z = sub_read_double(&str[++i]);
	printf("position successfully set to %f,%f,%f\n", out.x, out.y, out.z);
	return (out);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_read_pos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:12:53 by cpierre           #+#    #+#             */
/*   Updated: 2017/12/01 14:22:49 by cpierre          ###   ########.fr       */
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
	double	divisor;
	int		i;
	int		j;

	i = 0;
	big = str[i] == '-' ? atodouble(&str[++i]) * -1 : atodouble(&str[i]);
	small = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
	{
		j = i + 1;
		divisor = 1;
		while (str[j++] == '0')
			divisor = divisor * 10;
		small = atodouble(&str[i + 1]);
		while (small * divisor > 1)
			small /= 10.0;
	}
	else
		printf("Invalid double format given, setting to %f\n", big + small);
	return (big + small);
}

t_3d_double		sub_read_3d_double(t_str str)
{
	t_3d_double	out;
	int			i;

	if (str == NULL)
	{
		printf("unknown, set it to default: 0,0,0\n");
		return ((t_3d_double){0, 0, 0});
	}
	out.x = (double)ft_atof(str);
	i = -1;
	while (str[++i])
	{
		if (str[i] == ',')
			break ;
	}
	out.y = (double)ft_atof(&str[++i]);
	while (str[i])
	{
		if (str[i] == ',')
			break ;
		i++;
	}
	out.z = (double)ft_atof(&str[++i]);
	printf("successfully set to %f,%f,%f\n", out.x, out.y, out.z);
	return (out);
}

t_3d_double		sub_read_dir(t_str str)
{
	printf("direction ");
	return (sub_read_3d_double(str));
}

t_3d_double		sub_read_pos(t_str str)
{
	printf("position ");
	return (sub_read_3d_double(str));
}

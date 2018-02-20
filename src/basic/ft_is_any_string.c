/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_any_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 10:14:43 by cpierre           #+#    #+#             */
/*   Updated: 2018/02/20 09:30:32 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_is_any_string(t_str str, int n, ...)
{
	va_list	ap;
	size_t	i;
	int		out;

	va_start(ap, n);
	i = 0;
	out = 0;
	while ((int)++i <= n)
	{
		if (!ft_strcmp(str, va_arg(ap, t_str)))
			out++;
	}
	va_end(ap);
	return (out);
}

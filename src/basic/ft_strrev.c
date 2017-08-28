/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 17:17:45 by cpierre           #+#    #+#             */
/*   Updated: 2017/08/28 15:19:41 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	charswap(char *c, char *d)
{
	char tmp;

	tmp = *c;
	*c = *d;
	*d = tmp;
}

t_str		ft_strrev(t_str str)
{
	size_t	size;
	size_t	i;

	size = ft_strlen(str);
	i = -1;
	while (++i < (size / 2))
		charswap(&str[i], &str[size - i - 1]);
	return (str);
}

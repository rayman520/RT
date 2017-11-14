/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 12:38:31 by cpierre           #+#    #+#             */
/*   Updated: 2017/11/14 12:43:58 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_str_replace(char *str, char target, char new)
{
	if (str)
	{
		while (*str)
		{
			if (*str == target)
				*str = new;
			str++;
		}
	}
}

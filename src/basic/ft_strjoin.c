/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 13:33:27 by cpierre           #+#    #+#             */
/*   Updated: 2018/02/19 17:24:08 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_str	ft_strjoin(t_str s1, t_str s2)
{
	t_str	out;
	t_ul	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(out = (t_str)malloc(sizeof(char) * len)))
		return (NULL);
	ft_strcpy(out, s1);
	ft_strcat(out, s2);
	return (out);
}

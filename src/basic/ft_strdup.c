/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 15:06:31 by cpierre           #+#    #+#             */
/*   Updated: 2018/02/19 17:24:07 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_str	ft_strdup(t_str src)
{
	size_t	len;
	t_str	copy;

	len = ft_strlen(src);
	if (!(copy = (t_str)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strcpy(copy, src);
	return (copy);
}

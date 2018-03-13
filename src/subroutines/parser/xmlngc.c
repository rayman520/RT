/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmlngc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:35:50 by cpierre           #+#    #+#             */
/*   Updated: 2018/03/13 21:05:43 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char		*xmlngc(const xmlNode *cur)
{
	t_str str;

	if (cur->children && !ft_strcmp((const char *)cur->children->name, "text"))
	{
		str = (char *)xmlNodeGetContent(cur);
		if (!str || ft_strlen(str) < 1)
			ft_exit("this is our last hope");
		return (str);
	}
	else
		ft_exit("this is our last hope");
}

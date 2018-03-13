/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmlngc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:35:50 by cpierre           #+#    #+#             */
/*   Updated: 2018/03/13 20:20:49 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

char		*xmlngc(const xmlNode *cur)
{
	if (!ft_strcmp((const char *)cur->children->name, "text"))
		return ((char *)xmlNodeGetContent(cur));
	else
		ft_exit("this is our last hope");
}

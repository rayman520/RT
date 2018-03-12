/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tag_ception.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:48:26 by cpierre           #+#    #+#             */
/*   Updated: 2018/03/12 16:53:55 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_check_tag_ception(const char *name)
{
	if (!ft_strcmp(name, "object") || !ft_strcmp(name, "light") ||
		!ft_strcmp(name, "camera") || !ft_strcmp(name, "objects") ||
		!ft_strcmp(name, "lights") || !ft_strcmp(name, "cameras"))
		ft_exit("object-ception");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hey.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 14:35:59 by cpierre           #+#    #+#             */
/*   Updated: 2017/08/28 14:40:17 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	ft_hey(void)
{
	ft_putstr(CRED);
	ft_putstr("-=- ");
	ft_putstr(CGRN);
	ft_putstr("Hey ");
	ft_putstr(CRED);
	ft_putstr("-=-");
	ft_putstr(CRST);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_arg_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 11:11:06 by cpierre           #+#    #+#             */
/*   Updated: 2017/08/28 12:39:23 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

short	ft_arg_spell_test(char *arg)
{
	if (ft_strcmp(arg, "RENDER") &&
		ft_strcmp(arg, "EDIT") &&
		ft_strcmp(arg, "CREATE"))
		return (1);
	return (0);
}

void	ft_basic_arg_test(int ac, char **av)
{
	if (ac != 3 || ft_arg_spell_test(ft_strupcase(av[1])))
		ft_exit(ERR_USAGE);
}

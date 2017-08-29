/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_basic_arg_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 11:11:06 by cpierre           #+#    #+#             */
/*   Updated: 2017/08/29 13:06:49 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static	short	sub_arg_spell_test(char *arg)
{
	if (ft_strcmp(arg, "RENDER") &&
		ft_strcmp(arg, "EDIT") &&
		ft_strcmp(arg, "CREATE"))
		return (1);
	return (0);
}

static	short	sub_check_extensions(char *arg)
{
	short out;
	t_str tmp;

	tmp = ft_strdup("rt");
	out = sub_check_extension(arg, tmp);
	free(tmp);
	tmp = ft_strdup("xml");
	out += sub_check_extension(arg, tmp);
	free(tmp);
	tmp = ft_strdup("json");
	out += sub_check_extension(arg, tmp);
	free(tmp);
	if (out == 2)
		return (0);
	return (1);
}

void			sub_basic_arg_test(int ac, char **av)
{
	if (ac != 3)
		ft_exit(ERR_USAGE);
	ft_strupcase(av[1]);
	if (sub_arg_spell_test(av[1]))
		ft_exit(ERR_USAGE);
	if (sub_check_extensions(av[2]))
		ft_exit("Map extension not handled, please use .rt|.xml|.json\n");
}

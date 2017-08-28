/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic_arg_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 11:11:06 by cpierre           #+#    #+#             */
/*   Updated: 2017/08/28 15:18:30 by cpierre          ###   ########.fr       */
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

short	ft_check_extensions(char *arg)
{
	short out;
	t_str tmp;

	tmp = ft_strdup("rt");
	out = ft_check_extension(arg, tmp);
	free(tmp);
	tmp = ft_strdup("xml");
	out += ft_check_extension(arg, tmp);
	free(tmp);
	tmp = ft_strdup("json");
	out += ft_check_extension(arg, tmp);
	free(tmp);
	if (out == 2)
		return (0);
	return (1);
}

void	ft_basic_arg_test(int ac, char **av)
{
	char *upcase;

	if (ac != 3)
		ft_exit(ERR_USAGE);
	upcase = (char *)malloc(sizeof(char) * (ft_strlen(av[1]) + 1));
	ft_strcpy(upcase, av[1]);
	ft_strupcase(upcase);
	if (ft_arg_spell_test(upcase))
		ft_exit(ERR_USAGE);
	free(upcase);
	if (ft_check_extensions(av[2]))
		ft_exit("Map extension not handled, please use .rt|.xml|.json\n");
}

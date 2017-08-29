/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 10:26:29 by cpierre           #+#    #+#             */
/*   Updated: 2017/08/29 13:12:25 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	main(int ac, char **av)
{
	sub_basic_arg_test(ac, av);
	if (!ft_strcmp(av[1], "CREATE"))
		sub_create_file(av[2]);
	ft_putstr(av[1]);
	return (0);
}

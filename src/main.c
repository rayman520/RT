/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 10:26:29 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/05 17:40:25 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	main(int ac, char **av)
{
	sub_basic_arg_test(ac, av);
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		ft_exit("SDL_Init failed.\n");
	atexit(SDL_Quit);
	if (!ft_strcmp(av[1], "EDIT"))
		ft_putstr("edit");
	else if (!ft_strcmp(av[1], "RENDER"))
		full_render_start(av[2]);
	else if (!ft_strcmp(av[1], "CREATE"))
		sub_create_file(av[2]);
	return (0);
}

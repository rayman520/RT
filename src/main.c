/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 10:26:29 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/25 16:54:29 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int	main(int ac, char **av)
{
	sub_basic_arg_test(ac, av);
	LIBXML_TEST_VERSION
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		ft_exit("SDL_Init failed.\n");
	atexit(SDL_Quit);
	TTF_Init();
	atexit(TTF_Quit);
	atexit(xmlCleanupParser);
	if (!ft_strcmp(av[1], "EDIT"))
		editor_start(av[2]);
	else if (!ft_strcmp(av[1], "RENDER"))
		full_render_start(av[2]);
	else if (!ft_strcmp(av[1], "CREATE"))
		sub_create_file(av[2]);
	return (0);
}

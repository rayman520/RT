/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 10:26:29 by cpierre           #+#    #+#             */
/*   Updated: 2017/11/15 13:15:28 by nthibaud         ###   ########.fr       */
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
	if(!(IMG_Init(IMGINITFLAGS) & IMGINITFLAGS))
		ft_exit("SDL_image init failed.\n");
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

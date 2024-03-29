/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 10:26:29 by cpierre           #+#    #+#             */
/*   Updated: 2018/03/13 15:22:22 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		*create_perlinmap(void)
{
	int *permutation;
	int i;

	i = 0;
	if ((permutation = (int *)malloc(sizeof(int) * 256)) == NULL)
		ft_exit("perlin_tab malloc failed");
	if (permutation)
	{
		while (i < 256)
		{
			permutation[i] = rand() % 256;
			i++;
		}
	}
	else
		ft_exit("ERR_MLC");
	return (permutation);
}

int		main(int ac, char **av)
{
	t_fullmap	*map;

	sub_basic_arg_test(ac, av);
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		ft_exit("SDL_Init failed.\n");
	atexit(SDL_Quit);
	if (!(IMG_Init(IMGINITFLAGS) & IMGINITFLAGS))
		ft_exit("SDL_image init failed.\n");
	TTF_Init();
	atexit(TTF_Quit);
	atexit(xmlCleanupParser);
	if ((map = parser(av[2])) == NULL)
		ft_exit("map == NULL\n");
	map->perlin_tab = create_perlinmap();
	if (!ft_strcmp(av[1], "EDIT"))
		editor_start(av[2], map);
	else if (!ft_strcmp(av[1], "RENDER"))
		full_render_init(av[2], map);
	else if (!ft_strcmp(av[1], "CREATE"))
		ft_exit("Create option doesnt exist");
	free(map);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_create_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 13:08:24 by cpierre           #+#    #+#             */
/*   Updated: 2017/08/29 13:44:12 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	sub_create_file(t_str file)
{
	t_str full_path;

	mkdir("maps", 0777);
	if (!(full_path = ft_strjoin("maps/", file)))
	{
		ft_putstr("Failed to create map. Exiting...");
		exit(0);
	}
	mkdir(full_path, 0777);
	ft_putstr("file ");
	ft_putstr(full_path);
	ft_putstr(" created\n");
	free(full_path);
	exit(0);
}

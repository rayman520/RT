/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_create_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 13:08:24 by cpierre           #+#    #+#             */
/*   Updated: 2018/03/13 13:01:55 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	sub_create_file2(int fd, t_str mapfile)
{
	t_str tmp;

	tmp = ft_strdup("rt");
	if (!sub_check_extension(mapfile, tmp))
		ft_putstr("creating rt\n");
	free(tmp);
	tmp = ft_strdup("xml");
	if (!sub_check_extension(mapfile, tmp))
		sub_create_xml(fd);
	free(tmp);
	tmp = ft_strdup("json");
	if (!sub_check_extension(mapfile, tmp))
		ft_putstr("creating json\n");
	free(tmp);
}

void		sub_create_file(t_str file)
{
	t_str	full_path;
	int		fd;

	mkdir("maps", 0777);
	if (!(full_path = ft_strjoin("maps/", file)))
	{
		ft_putstr("Failed to create map. Exiting...");
		exit(0);
	}
	fd = open(full_path, O_RDONLY);
	if (fd >= 0)
	{
		ft_putstr("file already exists\n");
		free(full_path);
		close(fd);
		exit(0);
	}
	close(fd);
	fd = open(full_path, O_WRONLY | O_CREAT);
	sub_create_file2(fd, full_path);
	ft_putstr("file created\n");
	free(full_path);
	close(fd);
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_check_extension.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 14:13:24 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/05 22:02:48 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

short	sub_check_extension(t_str file, t_str ext)
{
	t_str	rfile;
	t_str	rext;
	int		cmp_out;

	rfile = ft_strdup(file);
	ft_strrev(rfile);
	rext = ft_strdup(ext);
	ft_strrev(rext);
	cmp_out = ft_strcmp(rfile, rext);
	free(rfile);
	free(rext);
	if (cmp_out == '.')
		return (0);
	return (1);
}

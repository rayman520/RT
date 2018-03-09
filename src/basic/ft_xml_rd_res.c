/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xml_rd_res.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:52:10 by cpierre           #+#    #+#             */
/*   Updated: 2018/03/09 15:37:54 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_2dint	ft_xml_ed_res(t_str input)
{
	t_2dint	out;
	int		i;

	if (!input)
		ft_exit("MAP ERROR\n");
	out.x = ft_atoi(input);
	if (out.x <= 5)
		out.x = EDITOR_IMG_WIDTH;
	i = 0;
	while (input[i] >= '0' && input[i] <= '9')
		i++;
	out.y = ft_atoi(&input[i + 1]);
	if (out.y <= 5)
		out.y = EDITOR_IMG_HEIGHT;
	free(input);
	return (out);
}

t_2dint	ft_xml_rd_res(t_str input)
{
	t_2dint	out;
	int		i;

	if (!input)
		ft_exit("MAP ERROR\n");
	out.x = ft_atoi(input);
	if (out.x <= 0)
		out.x = RENDER_WIN_WIDTH;
	i = 0;
	while (input[i] >= '0' && input[i] <= '9')
		i++;
	out.y = ft_atoi(&input[i + 1]);
	if (out.y <= 0)
		out.y = RENDER_WIN_HEIGHT;
	printf("Render resolution set to %dx%d\n", out.x, out.y);
	free(input);
	return (out);
}

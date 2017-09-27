/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xml_rd_res.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 15:52:10 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/25 16:28:48 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_2dint	ft_xml_rd_res(t_str input)
{
	t_2dint	out;
	int		i;

	if (!input)
		ft_exit("MAP ERROR\n");
	out.x = ft_atoi(input);
	if (out.x <= 0)
		ft_exit("Map Error: specified resolution invalid\n");
	i = 0;
	while (input[i] >= '0' && input[i] <= '9')
		i++;
	out.y = ft_atoi(&input[i + 1]);
	if (out.y <= 0)
		ft_exit("Map Error: specified resolution invalid\n");
	printf("Render resolution set to %dx%d\n", out.x, out.y);
	free(input);
	return (out);
}

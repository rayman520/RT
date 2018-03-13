/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_read_filter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 20:17:33 by nthibaud          #+#    #+#             */
/*   Updated: 2018/03/13 13:05:08 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_obj_t	sub_read_filter(t_str str)
{
	if (ft_is_any_string(str, 3, "DEFAULT", "DEF", "NOFILTER"))
		return (NOFILTER);
	if (ft_is_any_string(str, 2, "GRAYSCALE", "GRAY"))
		return (GRAYSCALE);
	if (ft_is_any_string(str, 1, "SEPIA"))
		return (SEPIA);
	if (ft_is_any_string(str, 2, "INVERTED", "INV"))
		return (INVERTED);
	else
		return (NOFILTER);
}

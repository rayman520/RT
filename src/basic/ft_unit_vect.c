/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unit_vect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 17:31:45 by cpierre           #+#    #+#             */
/*   Updated: 2017/10/10 12:53:55 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vect	ft_unit_vect(t_vect vect)
{
	t_vect out;
	double norm;

	out.pos = vect.pos;
	norm = ft_vect_norm(vect);
	out.dir.x = vect.dir.x / norm;
	out.dir.y = vect.dir.y / norm;
	out.dir.z = vect.dir.z / norm;
	return (out);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 12:52:33 by cpierre           #+#    #+#             */
/*   Updated: 2018/02/19 17:24:11 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	ft_vect_norm(t_vect vect)
{
	double norm;

	norm = vect.dir.x * vect.dir.x;
	norm += vect.dir.y * vect.dir.y;
	norm += vect.dir.z * vect.dir.z;
	return (sqrt(norm));
}

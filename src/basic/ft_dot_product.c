/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dot_product.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 20:54:47 by cpierre           #+#    #+#             */
/*   Updated: 2018/02/19 17:22:48 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double	ft_dot_product(t_vect v1, t_vect v2)
{
	double out;

	out = v1.dir.x * v2.dir.x;
	out += v1.dir.y * v2.dir.y;
	out += v1.dir.z * v2.dir.z;
	return (out);
}

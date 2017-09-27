/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_typedefs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 13:15:49 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/27 18:02:44 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TYPEDEFS_H
# define RT_TYPEDEFS_H

typedef char*	t_str;

typedef unsigned long t_ul;

typedef struct	s_2dint
{
	int			x;
	int			y;
}				t_2dint;

typedef struct	s_3d_double
{
	double		x;
	double		y;
	double		z;
}				t_3d_double;

typedef struct	s_light
{
	t_3d_double	pos;
	double		pow;
}				t_light;

typedef struct	s_object
{
	t_3d_double	pos;
}				t_object;

typedef struct	s_fullmap
{
	t_light		*light;
	t_object	*obj;
	t_2dint		res;
	t_str		mapfile_pathname;
	int			light_c;
	int			obj_c;
}				t_fullmap;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_typedefs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 13:15:49 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/23 16:35:50 by cpierre          ###   ########.fr       */
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

typedef struct	s_fullmap
{
	t_str		mapfile_pathname;
}				t_fullmap;

#endif

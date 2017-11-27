/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:15:19 by nthibaud          #+#    #+#             */
/*   Updated: 2017/11/22 12:24:51 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rt.h"

void	display_3d_double(char *s, t_3d_double v)
{
	printf("%s v(%.4f, %.4f, %.4f)\n", s, v.x, v.y, v.z);
}

void	display_2d_int(char *s, t_2dint v)
{
	printf("%s v(%d, %d)\n", s, v.x, v.y);
}

void	display_vect(char *s, t_vect v)
{
	printf("%s POS (%.4f, %.4f, %.4f)\n", s, v.pos.x, v.pos.y, v.pos.z);
	printf("%s DIR (%.4f, %.4f, %.4f)\n", s, v.dir.x, v.dir.y, v.dir.z);
}

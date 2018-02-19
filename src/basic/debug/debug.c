/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:15:19 by nthibaud          #+#    #+#             */
/*   Updated: 2018/02/19 17:10:33 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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

void	display_cam_vects(char *s, t_cam_vects cam_v)
{
	printf("-----------\n");
	printf("*** %s ***\n", s);
	printf("start X pos	%.4f\n", cam_v.start.pos.x);
	printf("start Y pos	%.4f\n", cam_v.start.pos.y);
	printf("start Z pos	%.4f\n", cam_v.start.pos.z);
	printf("- - -\n");
	printf("right X pos	%.4f\n", cam_v.right.pos.x);
	printf("right Y pos	%.4f\n", cam_v.right.pos.y);
	printf("right Z pos	%.4f\n", cam_v.right.pos.z);
	printf("- - -\n");
	printf("down X pos	%.4f\n", cam_v.down.pos.x);
	printf("down Y pos	%.4f\n", cam_v.down.pos.y);
	printf("down Z pos	%.4f\n", cam_v.down.pos.z);
	printf("\n");
	printf("start X dir	%.4f\n", cam_v.start.dir.x);
	printf("start Y dir	%.4f\n", cam_v.start.dir.y);
	printf("start Z dir	%.4f\n", cam_v.start.dir.z);
	printf("- - -\n");
	printf("right X dir	%.4f\n", cam_v.right.dir.x);
	printf("right Y dir	%.4f\n", cam_v.right.dir.y);
	printf("right Z dir	%.4f\n", cam_v.right.dir.z);
	printf("- - -\n");
	printf("down X dir	%.4f\n", cam_v.down.dir.x);
	printf("down Y dir	%.4f\n", cam_v.down.dir.y);
	printf("down Z dir	%.4f\n", cam_v.down.dir.z);
	printf("-----------\n");
}

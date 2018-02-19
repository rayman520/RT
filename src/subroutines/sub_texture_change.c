/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_texture_change.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 10:26:29 by bvan-dyc          #+#    #+#             */
/*   Updated: 2018/02/19 17:56:09 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static t_3d_double		makenoise_chess(t_hit hit)
{
	if (((int)(hit.pos.y + CHESS_SHIFT) / CHESS_TILESIZE +
		(int)(hit.pos.z + CHESS_SHIFT) / CHESS_TILESIZE +
		(int)(hit.pos.x + CHESS_SHIFT) / CHESS_TILESIZE) % 2 == 0)
	{
		hit.rgb_color.x /= 2;
		hit.rgb_color.y /= 2;
		hit.rgb_color.z /= 2;
	}
	return (hit.rgb_color);
}

static t_3d_double		makenoise_perlin(t_hit hit, int *perlin_tab)
{
	double		f;
	int			octave;

	octave = 1;
	while (octave < 10)
	{
		f += (1.0f / octave) *\
		fabsf((float)(noise3(octave * hit.pos.x * FREQUENCY,
			octave * hit.pos.y * FREQUENCY, octave * hit.pos.z *
			FREQUENCY, perlin_tab)));
		octave++;
	}
	hit.rgb_color.x = (1.0 - f + CONTRAST * f) * hit.rgb_color.x;
	hit.rgb_color.y = (1.0 - f + CONTRAST * f) * hit.rgb_color.y;
	hit.rgb_color.z = (1.0 - f + CONTRAST * f) * hit.rgb_color.z;
	return (hit.rgb_color);
}

static t_3d_double		makenoise_marble(t_hit hit, int *perlin_tab)
{
	float	f;
	int		octave;

	octave = 1;
	while (octave < 10)
	{
		f += (1.0f / octave) *\
		fabsf((float)(noise3(octave * hit.pos.x * FREQUENCY,
			octave * hit.pos.y * FREQUENCY, octave * hit.pos.z *
			FREQUENCY, perlin_tab)));
		octave++;
	}
	f = 1 - sqrt(fabs(sin(2 * PI * f)));
	hit.rgb_color.x = (1.0 - f + CONTRAST * f) * hit.rgb_color.x;
	hit.rgb_color.y = (1.0 - f + CONTRAST * f) * hit.rgb_color.y;
	hit.rgb_color.z = (1.0 - f + CONTRAST * f) * hit.rgb_color.z;
	return (hit.rgb_color);
}

t_3d_double				sub_texture_change(t_hit hit, t_fullmap *map)
{
	if (hit.obj->texture_type == CHESS)
		hit.rgb_color = makenoise_chess(hit);
	if (hit.obj->texture_type == PERLIN)
		hit.rgb_color = makenoise_perlin(hit, map->perlin_tab);
	if (hit.obj->texture_type == MARBLE)
		hit.rgb_color = makenoise_marble(hit, map->perlin_tab);
	hit.rgb_color.x = floor(hit.rgb_color.x);
	hit.rgb_color.y = floor(hit.rgb_color.y);
	hit.rgb_color.z = floor(hit.rgb_color.z);
	return (hit.rgb_color);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noise.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 10:26:29 by cpierre           #+#    #+#             */
/*   Updated: 2017/12/01 16:22:53 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double fade(double t)
{
    return (t * t * t * (t * (t * 6 - 15) + 10));
}

static double lerp(double t, double a, double b)
{
    return (a + t * (b - a));
}

static double grad(int hash, double x, double y, double z)
{
    int h;
    double u;
	double v;

	h = hash & 15;
	u = ((h < 8 || h == 12 || h == 13) ? x : y);
    v = ((h < 4|| h == 12|| h == 13) ? y : z);
    return (((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v));
}

double compute_noise(t_noise perlin, double x, double y, double z)
{
	return (lerp(perlin.w, lerp(perlin.v, lerp(perlin.u,\
 grad(perlin.tab[perlin.aa], x, y, z),\
 grad(perlin.tab[perlin.ba], x - 1, y, z)),\
 lerp(perlin.u, grad(perlin.tab[perlin.ab], x, y - 1, z),\
 grad(perlin.tab[perlin.bb], x - 1, y - 1, z))),\
 lerp(perlin.v, lerp(perlin.u, grad(perlin.tab[perlin.aa + 1], x, y, z - 1 ),\
 grad(perlin.tab[perlin.ba + 1], x - 1, y, z - 1)),\
 lerp(perlin.u, grad(perlin.tab[perlin.ab + 1], x, y - 1, z - 1),\
 grad(perlin.tab[perlin.bb + 1], x - 1, y - 1, z - 1)))));
}

double noise3(double x, double y, double z, int *perlin_tab)
{
	t_noise 	perlin;
	int 		i;

	i = 0;
	while (i < 256)
    {
		perlin.tab[i] = perlin_tab[i];
		perlin.tab[256 + i] = perlin_tab[i];
		i++;
	}
    perlin.cx = (int)floor(x) & 255;
    perlin.cy = (int)floor(y) & 255;
    perlin.cz = (int)floor(z) & 255;
    x  -= floor(x);
    y  -= floor(y);
    z  -= floor(z);
    perlin.u = fade(x);
    perlin.v = fade(y);
    perlin.w = fade(z);
    perlin.a = perlin.tab[perlin.cx] + perlin.cy;
	perlin.aa = perlin.tab[perlin.a] + perlin.cz;
	perlin.ab = perlin.tab[perlin.a + 1] + perlin.cz;
    perlin.b = perlin.tab[perlin.cx + 1] + perlin.cy;
	perlin.ba = perlin.tab[perlin.b] + perlin.cz;
	perlin.bb = perlin.tab[perlin.b + 1] + perlin.cz;
    return (compute_noise(perlin, x, y, z));
}

void	makenoise_chess(t_hit hit)
{
	if (((int)(hit.pos.y + CHESS_SHIFT) / CHESS_TILESIZE\
	 + (int)(hit.pos.z + CHESS_SHIFT) / CHESS_TILESIZE + \
	 (int)(hit.pos.x + CHESS_SHIFT) / CHESS_TILESIZE) % 2 == 0)
	{
		hit.obj->rgb_color.x /= 2;
		hit.obj->rgb_color.y /= 2;
		hit.obj->rgb_color.z /= 2;
	}
}

void	makenoise_perlin(t_hit hit, int *perlin_tab)
{
	double		f;
	int 		octave;

	octave = 1;
	while (octave < 10)
	{
		f += (1.0f / octave) *\
		fabsf((float)(noise3(octave * hit.pos.x * FREQUENCY,\
		octave * hit.pos.y * FREQUENCY, octave * hit.pos.z *\
		 FREQUENCY, perlin_tab)));
		octave++;
	};
	hit.obj->rgb_color.x = (1.0 - f + CONTRAST * f) * hit.obj->rgb_color.x;
	hit.obj->rgb_color.y = (1.0 - f + CONTRAST * f) * hit.obj->rgb_color.y;
	hit.obj->rgb_color.z = (1.0 - f + CONTRAST * f) * hit.obj->rgb_color.z;
}

void 	makenoise_marble(t_hit hit, int *perlin_tab)
{
	float f;
	int octave;

	octave = 1;
	while (octave < 10)
	{
		f += (1.0f / octave) *\
		fabsf((float)(noise3(octave * hit.pos.x * FREQUENCY,\
		octave * hit.pos.y * FREQUENCY, octave * hit.pos.z *\
		 FREQUENCY, perlin_tab)));
		octave++;
	};
	f = 1 - sqrt(fabs(sin(2 * PI * f)));
	hit.obj->rgb_color.x = (1.0 - f + CONTRAST * f) * hit.obj->rgb_color.x;
	hit.obj->rgb_color.y = (1.0 - f + CONTRAST * f) * hit.obj->rgb_color.y;
	hit.obj->rgb_color.z = (1.0 - f + CONTRAST * f) * hit.obj->rgb_color.z;
}
void 	sub_texturechange(t_hit hit, t_fullmap *map)
{
	if (hit.obj->texture_type == CHESS)
		makenoise_chess(hit);
	if (hit.obj->texture_type == PERLIN)
		makenoise_perlin(hit, map->perlin_tab);
	if (hit.obj->texture_type == MARBLE)
		makenoise_marble(hit, map->perlin_tab);
	hit.obj->rgb_color.x = floor(hit.obj->rgb_color.x);
	hit.obj->rgb_color.y = floor(hit.obj->rgb_color.y);
	hit.obj->rgb_color.z = floor(hit.obj->rgb_color.z);
}

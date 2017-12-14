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

static int permutation[] = { 151,160,137,91,90,15,
   131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,8,99,37,240,21,10,23,
   190, 6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,
   88,237,149,56,87,174,20,125,136,171,168, 68,175,74,165,71,134,139,48,27,166,
   77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,
   102,143,54, 65,25,63,161, 1,216,80,73,209,76,132,187,208, 89,18,169,200,196,
   135,130,116,188,159,86,164,100,109,198,173,186, 3,64,52,217,226,250,124,123,
   5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,
   223,183,170,213,119,248,152, 2,44,154,163, 70,221,153,101,155,167, 43,172,9,
   129,22,39,253, 19,98,108,110,79,113,224,232,178,185, 112,104,218,246,97,228,
   251,34,242,193,238,210,144,12,191,179,162,241, 81,51,145,235,249,14,239,107,
   49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,127, 4,150,254,
   138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180
   };

int *create_noisetab()
{
	int *permutation;
	int i;

	i = 0;
	permutation = (int *)malloc(sizeof(int) * 256);
	while (i < 256)
	{
		permutation[i] = rand() % 256;
		i++;
	}
	return(permutation);
}

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
    return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
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

double noise3(double x, double y, double z)
{
	t_noise 	perlin;
	int 		i;

	i = 0;
	while (i < 256)
    {
		perlin.tab[i] = permutation[i];
		perlin.tab[256 + i] = permutation[i];
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

void	makenoise_perlin(t_hit hit)
{
	double		f;
	int 		octave;

	octave = 1;
	while (octave < 10)
	{
		f += (1.0f / octave) *\
		fabsf((float)(noise3(octave * hit.pos.x * FREQUENCY,\
		octave * hit.pos.y * FREQUENCY, octave * hit.pos.z * FREQUENCY)));
		octave++;
	};
	hit.obj->rgb_color.x = (1.0 - f + CONTRAST * f) * hit.obj->rgb_color.x;
	hit.obj->rgb_color.y = (1.0 - f + CONTRAST * f) * hit.obj->rgb_color.y;
	hit.obj->rgb_color.z = (1.0 - f + CONTRAST * f) * hit.obj->rgb_color.z;
}

void 	makenoise_marble(t_hit hit)
{
	float f;
	int octave;

	octave = 1;
	while (octave < 10)
	{
		f += (1.0f / octave) *\
		fabsf((float)(noise3(octave * hit.pos.x * FREQUENCY,\
		octave * hit.pos.y * FREQUENCY, octave * hit.pos.z * FREQUENCY)));
		octave++;
	};
	f = 1 - sqrt(fabs(sin(2 * PI * f)));
	hit.obj->rgb_color.x = (1.0 - f + CONTRAST * f) * hit.obj->rgb_color.x;
	hit.obj->rgb_color.y = (1.0 - f + CONTRAST * f) * hit.obj->rgb_color.y;
	hit.obj->rgb_color.z = (1.0 - f + CONTRAST * f) * hit.obj->rgb_color.z;
}

void 	sub_texturechange(t_hit hit)
{
	if (hit.obj->texture_type == CHESS)
		makenoise_chess(hit);
	if (hit.obj->texture_type == PERLIN)
		makenoise_perlin(hit);
	if (hit.obj->texture_type == MARBLE)
		makenoise_marble(hit);
}

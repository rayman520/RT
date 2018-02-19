/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_texture_change.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 10:26:29 by bvan-dyc          #+#    #+#             */
/*   Updated: 2018/02/07 16:11:49 by bvan-dyc         ###   ########.fr       */
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

static double	compute_noise(t_noise perlin, double x, double y, double z)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace_editor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 16:24:21 by cpierre           #+#    #+#             */
/*   Updated: 2017/12/04 14:39:43 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double	get_light_coef(t_fullmap *map, t_hit hit)
{
	double	out;
	int		i;
	int		j;
	t_vect	light_vect;
	double	coef;
	double	total_power;
	t_hit	shadow_hit;

	out = 0;
	i = -1;
	total_power = 0;
	light_vect.pos = hit.pos;
	while (++i < map->light_c)
	{
		light_vect.dir.x = map->light[i].pos.x - hit.pos.x;
		light_vect.dir.y = map->light[i].pos.y - hit.pos.y;
		light_vect.dir.z = map->light[i].pos.z - hit.pos.z;
		j = -1;
		shadow_hit = sub_inter_objects(map, ft_unit_vect(light_vect));
		if (shadow_hit.obj == NULL)
		{
			coef = ft_dot_product((t_vect){hit.pos, hit.normal_dir}, ft_unit_vect(light_vect));
			out += (coef * map->light[i].pow);
		}
		else if (shadow_hit.dist > ft_vect_norm(light_vect))
		{
			coef = ft_dot_product((t_vect){hit.pos, hit.normal_dir}, ft_unit_vect(light_vect));
			out += (coef * map->light[i].pow);
		}
		total_power += map->light[i].pow;
	}
	out = out / total_power;
	return (out);
}

static t_rgb	get_color(t_hit hit, double amb_coef, double light)
{
	t_rgb					out;
	t_ui					color;
	static t_texture_ft_tab	funct_tab =
	{
		sub_texture_sphere
	};

	if (hit.obj->texture)
		color = funct_tab[hit.obj->type - 1](hit);
	else
		color = hit.obj->color;
	light = amb_coef + (1 - amb_coef) * (light > 0 ? light : 0);
	out.r = (int)(((color & 0xFF0000) >> 16) * light);
	out.g = (int)(((color & 0x00FF00) >> 8) * light);
	out.b = (int)((color & 0x0000FF) * light);
	return (out);
}

t_ui			raytrace_editor(t_fullmap *map, t_vect ray)
{
	t_rgb		color;
	t_hit		hit;
	double		light_coef;

	light_coef = 0;
	hit = sub_inter_objects(map, ray);
	if (!(hit.dist < RENDER_DIST))
		return (20);
	if (map->light_c)
		light_coef = get_light_coef(map, hit);
	color = get_color(hit, map->amb_coef, light_coef);
	return (ft_rgb_to_int(color));
}

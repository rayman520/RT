/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_inter_objects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:08:27 by nthibaud          #+#    #+#             */
/*   Updated: 2018/02/20 11:37:04 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	rt_check_minmax(t_3d_double min, t_3d_double max, t_hit *hit)
{
	if (hit->pos.x < min.x || hit->pos.x > max.x)
		hit->is_hit = 0;
	if (hit->pos.y < min.y || hit->pos.y > max.y)
		hit->is_hit = 0;
	if (hit->pos.z < min.z || hit->pos.z > max.z)
		hit->is_hit = 0;
}

void	init(t_hit *hit, t_hit (**function_tab)(t_object *, t_vect ray))
{
	function_tab[0] = &sub_inter_sphere;
	function_tab[1] = &sub_inter_cone;
	function_tab[2] = &sub_inter_cylinder;
	function_tab[3] = &sub_inter_plane;
	function_tab[4] = &sub_inter_disk;
	function_tab[5] = &sub_inter_triangle;
	function_tab[6] = &sub_inter_quadrangle;
	function_tab[7] = &sub_inter_pyramid_tbase;
	function_tab[8] = &sub_inter_quadrangle;
	function_tab[9] = &sub_inter_paraboloid;
	function_tab[10] = &sub_inter_hyperboloid;
	*hit = (t_hit){NULL_POS, NULL_POS, NULL_POS, NULL_VECT, NULL, RENDER_DIST,
		RENDER_DIST, 0, (t_3d_double){0, 0, 0}, (t_3d_double){0, 0, 0}};
}

t_hit	negative_ray(t_fullmap *map, t_vect ray, t_hit hit)
{
	t_vect					neg_ray;

	neg_ray = ray;
	neg_ray.pos = hit.pos2;
	hit = sub_inter_objects(map, neg_ray);
	return (hit);
}

t_hit	sub_inter_objects(t_fullmap *map, t_vect ray)
{
	t_hit					hit;
	t_hit					new_hit;
	int						i;
	t_hit					(**function_tab)(t_object *obj, t_vect ray);

	function_tab = NULL;
	function_tab = malloc(sizeof(void *) * 11);
	init(&hit, function_tab);
	i = -1;
	while (++i < map->obj_c)
	{
		new_hit = function_tab[map->obj[i].type - 1](&map->obj[i], ray);
		rt_check_minmax(new_hit.obj->min, new_hit.obj->max, &new_hit);
		if (new_hit.is_hit == 1 && new_hit.dist < hit.dist && new_hit.dist > \
			EPSILON)
			hit = new_hit;
	}
	if (hit.is_hit == 1 && hit.obj->type >= 1 && hit.obj->type <= 3 && \
		hit.obj->negative == YES)
		hit = negative_ray(map, ray, hit);
	free(function_tab);
	return (hit);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_inter_disk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvan-dyc <bvan-dyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:08:27 by bvan-dyc          #+#    #+#             */
/*   Updated: 2018/02/19 17:10:57 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_hit	sub_inter_disk(t_object *disk, t_vect ray)
{
	t_3d_double		tmp;
	t_3d_double		p;
	t_3d_double		v;
	float			d2;
	t_hit			hit;

	hit = sub_inter_plane(disk, ray);
	if (hit.is_hit == 1)
	{
		tmp = v_mult_by_nb(ray.dir, hit.dist);
		p = v_sum(ray.pos, tmp);
		v = v_sub_a_by_b(p, disk->pos);
		d2 = v_dot(v, v);
		if (sqrtf(d2) <= disk->radius)
			hit.is_hit = 1;
		else
			hit.is_hit = 0;
	}
	return (hit);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_inter_disk.c		                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:49:37 by nthibaud          #+#    #+#             */
/*   Updated: 2017/11/28 16:52:20 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_hit 	sub_inter_disk(t_object *disk, t_vect ray)
{
	t_3d_double 	tmp;
	t_3d_double 	p;
	t_3d_double		v;
	float			dist2;
	t_hit			hit;

	hit = sub_inter_plane(disk, ray);
	if (hit.dist == 1)
	{
		tmp = v_mult_by_nb(ray.dir, hit.dist);
		p = v_sum(ray.pos, tmp);
		v = v_sub_a_by_b(p, disk->pos);
		dist2 = v_dot(v, v);
		if (sqrtf(dist2) <= disk->radius)
			hit.is_hit = 1;
		else
			hit.is_hit = 0;
	}
   else
   		hit.is_hit = 0;
	return (hit);
}

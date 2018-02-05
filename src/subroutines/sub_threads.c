/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:34:55 by nthibaud          #+#    #+#             */
/*   Updated: 2018/02/05 16:49:29 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		*calc_screen_pixel(void *arg)
{
	t_2dint			pos;
	t_vect			ray;
	Uint32			color;
	t_rend_zone		*zone;

	zone = (t_rend_zone *)arg;
	pos.y = zone->pos_start;
	while (pos.y < zone->pos_end)
	{
		pos.x = -1;
		while (++pos.x < zone->img_w)
		{
			ray = sub_calc_pix_vect(zone->map.cam_v, pos,
					zone->img_w, zone->img_h);
			color = ft_double_3d_to_int(raytrace_fullrender(&zone->map, ray));
			zone->color_tab[pos.y - zone->pos_start][pos.x] = color;
		}
		pos.y += 1;
	}
	pthread_exit((void *)zone);
}

static	void	draw_zones(t_rend_zone *zone_tab, t_SDL_Bundle b)
{
	t_2dint			pos;
	int				i;

	i = 0;
	while (i < THREADS_NB)
	{
		pos.x = 0;
		pos.y = zone_tab[i].pos_start;
		while (pos.y < zone_tab[i].pos_end)
		{
			pos.x = 0;
			while (pos.x < b.render_img->w)
			{
				ft_putunlckpixel(b.render_img, pos,
						zone_tab[i].color_tab[pos.y -
						zone_tab[i].pos_start][pos.x]);
				pos.x += 1;
			}
			pos.y += 1;
		}
		i++;
	}
}

void			create_threads(t_rend_zone *zone_tab, int i, pthread_t *threads)
{
	int				ret;
	pthread_attr_t	attr;

	ret = 1;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	ret = pthread_create(&threads[i], &attr,
			calc_screen_pixel, (void *)&zone_tab[i]);
	if (ret != 0)
		ft_exit("Creating thread error\n");
	pthread_attr_destroy(&attr);
}

void			join_threads(pthread_t *threads, t_rend_zone *zone_tab,
		t_SDL_Bundle b)
{
	void			*status;
	int				ret;
	int				i;

	i = 0;
	ret = 1;
	while (i < THREADS_NB)
	{
		ret = pthread_join(threads[i], &status);
		if (ret != 0)
			ft_exit("Joining thread error\n");
		i++;
	}
	draw_zones(zone_tab, b);
}

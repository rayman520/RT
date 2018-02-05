/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_render_threads.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:39:18 by nthibaud          #+#    #+#             */
/*   Updated: 2018/02/05 16:49:03 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			free_all(t_rend_zone *zone_tab,
		t_zone_pos zone_pos, pthread_t *threads)
{
	int			i;
	int			j;

	i = 0;
	if (zone_tab != NULL)
	{
		while (i < THREADS_NB)
		{
			j = -1;
			if (zone_tab[i].color_tab != NULL)
			{
				while (++j < zone_pos.diff)
				{
					if (zone_tab[i].color_tab[j] != NULL)
						free(zone_tab[i].color_tab[j]);
				}
			}
			free(zone_tab[i].color_tab);
			i++;
		}
		free(zone_tab);
	}
	if (threads != NULL)
		free(threads);
}

static void			create_color_tab(t_rend_zone *zone_tab, int i, int pos_diff)
{
	int			j;

	j = 0;
	if ((zone_tab[i].color_tab =
				(int **)malloc(sizeof(int *) * pos_diff)) == NULL)
		ft_exit("zone_tab[i].color_tab malloc error\n");
	while (j < pos_diff)
	{
		if ((zone_tab[i].color_tab[j] =
					(int *)malloc(sizeof(int) * zone_tab[i].img_w)) == NULL)
			ft_exit("zone_tab[i].color_tab[j] malloc error\n");
		j++;
	}
}

static t_rend_zone	zone_init(t_fullmap *map, int i,
		t_zone_pos zone_pos, t_SDL_Bundle b)
{
	t_rend_zone	zone;

	zone.thread_nb = i;
	zone.map = *map;
	zone.pos_start = zone_pos.start;
	zone.pos_end = zone_pos.end;
	zone.img_w = b.render_img->w;
	zone.img_h = b.render_img->h;
	return (zone);
}

static t_zone_pos	first_zone_calc(t_SDL_Bundle b)
{
	t_zone_pos	zone_pos;

	if (THREADS_NB <= 0 || THREADS_NB > 709 ||
			b.render_img->h % THREADS_NB != 0)
		ft_exit("Wrong thread number\n");
	zone_pos.start = 0;
	zone_pos.end = b.render_img->h / THREADS_NB;
	zone_pos.diff = zone_pos.end;
	return (zone_pos);
}

void				full_render_threads(t_fullmap *map, t_SDL_Bundle b)
{
	int			i;
	t_zone_pos	zone_pos;
	t_rend_zone	*zone_tab;
	pthread_t	*threads;

	i = 0;
	zone_pos = first_zone_calc(b);
	if ((zone_tab = (t_rend_zone *)
				malloc(sizeof(t_rend_zone) * THREADS_NB)) == NULL)
		ft_exit("zone_tab malloc error\n");
	if ((threads = (pthread_t *)malloc(sizeof(pthread_t) * THREADS_NB)) == NULL)
		ft_exit("threads malloc error\n");
	while (i < THREADS_NB)
	{
		zone_tab[i] = zone_init(map, i, zone_pos, b);
		create_color_tab(zone_tab, i, zone_pos.diff);
		create_threads(zone_tab, i, threads);
		zone_pos.start += zone_pos.diff;
		zone_pos.end += zone_pos.diff;
		i++;
	}
	join_threads(threads, zone_tab, b);
	free_all(zone_tab, zone_pos, threads);
}

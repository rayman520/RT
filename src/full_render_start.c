/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_render_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:28:54 by nthibaud          #+#    #+#             */
/*   Updated: 2018/01/23 17:32:38 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	save_image(SDL_Surface *img, int i, t_str mapfile)
{
	t_str	savefile_name;
	t_str	tmp;

	savefile_name = ft_strjoin("renders\\RT_Full-render_", mapfile);
	tmp = ft_strjoin(savefile_name, ft_itoa(i));
	savefile_name = ft_strjoin(tmp, ".bmp");
	free(tmp);
	ft_str_replace(savefile_name, '/', '_');
	ft_str_replace(savefile_name, '\\', '/');
	SDL_SaveBMP(img, savefile_name);
	printf("%s", SDL_GetError());
	free(savefile_name);
}

static void	*calc_screen_pixel(void *arg)
{
	t_2dint		pos;
	t_vect		ray;
	Uint32		color;
	t_rend_zone	*zone;

	zone = (t_rend_zone *)arg;
	pos.y = zone->pos_start;
	while (pos.y < zone->pos_end)
	{
		pos.x = -1;
		while (++pos.x < zone->img_w)
		{
			ray = sub_calc_pix_vect(zone->map.cam_v, pos, zone->img_w, zone->img_h);
			color = ft_double_3d_to_int(raytrace_fullrender(&zone->map, ray));
			zone->color_tab[pos.y - zone->pos_start][pos.x] = color;
		}
		pos.y += 1;
	}
	pthread_exit((void *)zone);
}

	void create_color_tab(t_rend_zone *zone_tab, int i, int pos_diff)
	{
		int		j;

		j = 0;
		if ((zone_tab[i].color_tab = (int **)malloc(sizeof(int *) * pos_diff)) == NULL)
			exit(EXIT_SUCCESS);
		while (j < pos_diff)
		{
			if ((zone_tab[i].color_tab[j] = (int *)malloc(sizeof(int) * zone_tab[i].img_w)) == NULL)
				exit(EXIT_SUCCESS);
			j++;
		}
	}

	void	create_threads(t_rend_zone *zone_tab, int i, pthread_t *threads)
	{
		int		ret;
		pthread_attr_t	attr;
	
		ret = 1;
		pthread_attr_init(&attr);
		pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
		ret = pthread_create(&threads[i], &attr, calc_screen_pixel, (void *)&zone_tab[i]);
		if (ret != 0)
			exit(EXIT_SUCCESS);
		pthread_attr_destroy(&attr);
	}

	void	join_threads(pthread_t *threads)
	{
		void	*status;
		int		ret;
		int		i;

		i = 0;
		ret = 1;
		while (i < THREADS_NB)
		{		ret = pthread_join(threads[i], &status);
			if (ret != 0)
				exit(EXIT_SUCCESS);
			i++;
		}
	}

	void	draw_zones(t_rend_zone *zone_tab, t_SDL_Bundle b)
	{
		t_2dint pos;
		int		i;

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
					ft_putunlckpixel(b.render_img, pos, zone_tab[i].color_tab[pos.y - zone_tab[i].pos_start][pos.x]);
					pos.x += 1;
				}
				pos.y += 1;
			}
		i++;
		}
	}

t_rend_zone	zone_init(t_fullmap *map, int i, t_zone_pos zone_pos, t_SDL_Bundle b)
{
	t_rend_zone		zone;

	zone.thread_nb = i;
	zone.map = *map;
	zone.pos_start = zone_pos.start;
	zone.pos_end = zone_pos.end;
	zone.img_w = b.render_img->w;
	zone.img_h = b.render_img->h;
	return (zone);
}

t_zone_pos		first_zone_calc(t_SDL_Bundle b)
{
	t_zone_pos	zone_pos;

	if (THREADS_NB <= 0)
		exit(EXIT_SUCCESS);
	if (THREADS_NB > 709)
		exit(EXIT_SUCCESS);
	if ((b.render_img->h % THREADS_NB) != 0)
		exit(EXIT_SUCCESS);
	zone_pos.start = 0;
	zone_pos.end = b.render_img->h / THREADS_NB;
	zone_pos.diff = zone_pos.end;
	return (zone_pos);
}

static	void	calc_screen_image(t_fullmap *map, t_SDL_Bundle b)
{
	int				i;
	t_zone_pos		zone_pos;
	t_rend_zone		*zone_tab;
	pthread_t		*threads;

	i = 0;
	zone_pos = first_zone_calc(b);
	zone_tab = (t_rend_zone *)malloc(sizeof(t_rend_zone) * THREADS_NB);
	threads = (pthread_t *)malloc(sizeof(pthread_t) * THREADS_NB);
	while (i < THREADS_NB)
	{
		zone_tab[i] = zone_init(map, i, zone_pos, b);
		create_color_tab(zone_tab, i, zone_pos.diff);
		create_threads(zone_tab, i, threads);
		zone_pos.start += zone_pos.diff;
		zone_pos.end += zone_pos.diff;
		i++;
	}
	join_threads(threads);
	draw_zones(zone_tab, b);
}

void	full_render_start(t_SDL_Bundle b, t_fullmap *map, t_str mapfile)
{
	int			i;
	int			image_number;

	image_number = 1;
	i = 0;
	while (i < image_number)
	{
		SDL_LockSurface(b.render_img);
		calc_screen_image(map, b);
		SDL_UnlockSurface(b.render_img);
		save_image(b.render_img, i, mapfile);
		sub_blit_render(b.render_img, b.window_img);
		SDL_UpdateWindowSurface(b.render_win);
		i++;
	}
}

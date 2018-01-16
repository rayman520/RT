/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_render_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:28:54 by nthibaud          #+#    #+#             */
/*   Updated: 2018/01/16 18:27:43 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static pthread_mutex_t		mutex = PTHREAD_MUTEX_INITIALIZER;

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
/*
static void	browse_screen_pixel(t_fullmap *map, t_SDL_Bundle b, int img_nb, int i)
{
	t_2dint		pos;
	t_vect		ray;

	pos.y = -1;
	while (++pos.y < b.render_img->h)
	{
		pos.x = -1;
		while (++pos.x < b.render_img->w)
		{
			ray = sub_calc_pix_vect(map->cam_v, pos, b.render_img);
			ft_putunlckpixel(b.render_img, pos,
				ft_double_3d_to_int(raytrace_fullrender(map, ray)));
		}
		sub_put_percent(b.render_win, b.window_img, 100 * (double)(pos.y +
			i * b.render_img->h) / (b.render_img->h * img_nb));
	}
}
*/
static void	*browse_screen_pixel(void *arg)
{
	t_fullmap	*map;
	t_2dint		pos;
	t_vect		ray;
	Uint32		color;


	map = (t_fullmap *)arg;
	pos.y = map->zone.pos_start;
	printf("START %d thread nb %d\n", pos.y, map->zone.num);
	printf("END %d thread nb %d\n", map->zone.pos_end, map->zone.num);
	while (pos.y < map->zone.pos_end)
	{
		pos.x = -1;
		while (++pos.x < map->zone.img_w)
		{
		ray = sub_calc_pix_vect(map->cam_v, pos, map->zone.img_w, map->zone.img_h);
		color = ft_double_3d_to_int(raytrace_fullrender(map, ray));

		map->zone.color_tab[pos.y - map->zone.pos_start][pos.x] = color;
	//	printf("%d RES\n", map->zone.color_tab[map->zone.pos_diff - 1][map->zone.img_w - 1]);
	//	printf("COLOR %d\n", map->zone.color_tab[pos.y - map->zone.pos_start][pos.x]);
		
	//	printf("[%d][%d] ", pos.y - map->zone.pos_start, pos.x);
	//	map->zone.color_tab[100][100] = 10;
		//	ft_putunlckpixel(map->b->render_img, pos, color);
		}
		pos.y += 1;
	//	sub_put_percent(b.render_win, b.window_img, 100 * (double)(pos.y +
	//		i * b.render_img->h) / (b.render_img->h * img_nb));
	}
	pthread_exit((void *)&map->zone);
}

static	void	pthread_init(t_fullmap *map, t_SDL_Bundle b)
{
	int				i;
	int				j;
	int				ret;
	int				pos_start;
	int				pos_end;
	int				pos_diff;
	void			*status;
	t_rend_zone		*zone;
	pthread_t		*threads;
	t_fullmap		*maps;
	pthread_attr_t	attr;

	i = 0;
	printf("THREAD NB %d\n", THREADS_NB);
	threads = (pthread_t *)malloc(sizeof(pthread_t) * THREADS_NB);
	maps = (t_fullmap *)malloc(sizeof(t_fullmap) * THREADS_NB);
	pos_start = 0;
	pos_end = b.render_img->h / THREADS_NB;
	pos_diff = pos_end;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
	if (pthread_mutex_init(&mutex, NULL) != 0)
		exit(EXIT_SUCCESS);
	while (i < THREADS_NB)
	{
		maps[i] = *map;
		maps[i].zone.num = i;
		maps[i].zone.pos_start = pos_start;
		maps[i].zone.pos_end = pos_end;
		maps[i].zone.pos_diff = pos_diff;
		maps[i].zone.img_w = b.render_img->w;
		maps[i].zone.img_h = b.render_img->h;
		if ((maps[i].zone.color_tab = (int **)malloc(sizeof(int *) * pos_diff)) == NULL)
			printf("||MALLOC ALLOCATE ERROR 1|| ");
		j = 0;
		while (j < pos_diff)
		{
			if ((maps[i].zone.color_tab[j] = (int *)malloc(sizeof(int) * maps[i].zone.img_w)) == NULL)
			printf("||MALLOC ALLOCATE ERROR 2|| ");
			j++;
		}
		ret = pthread_create(&threads[i], &attr, browse_screen_pixel, (void *)&maps[i]);
		if (ret != 0)
			exit(EXIT_SUCCESS);
		printf("THREAD CREATED\n");
		pos_start += pos_diff;
		pos_end += pos_diff;
		i++;
	}
	pthread_attr_destroy(&attr);
	i = 0;
	while (i < THREADS_NB)
	{
		ret = pthread_join(threads[i], &status);
		ret = 0;
		if (ret != 0)
		{
			printf("joining problem\n");
			exit(EXIT_SUCCESS);
		}
		printf("JOIN THREAD\n");
		zone = status;
		printf("THREAD NUM %d JOINED start %d end %d\n", zone->num, zone->pos_start, zone->pos_end);
		i++;
	t_2dint pos;
	pos.x = 0;
	pos.y = zone->pos_start;
	while (pos.y < zone->pos_end)
	{
		pos.x = 0;
		while (pos.x < b.render_img->w)
		{
			ft_putunlckpixel(b.render_img, pos, zone->color_tab[pos.y - zone->pos_start][pos.x]);
			pos.x += 1;
		}
		pos.y += 1;
	}

	}
	pthread_mutex_destroy(&mutex);
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
		pthread_init(map, b);
//		browse_screen_pixel(map, b, image_number, i);
		SDL_UnlockSurface(b.render_img);
		save_image(b.render_img, i, mapfile);
		sub_blit_render(b.render_img, b.window_img);
		SDL_UpdateWindowSurface(b.render_win);
		i++;
	}
}

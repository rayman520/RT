/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_prototypes_main.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:00:40 by nthibaud          #+#    #+#             */
/*   Updated: 2018/03/13 15:47:38 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PROTOTYPES_MAIN_H
# define RT_PROTOTYPES_MAIN_H

# include "rt.h"

/*
**	Main functions
*/
void			editor_start(t_str mapfile, t_fullmap *map);
int				main(int ac, char **av);
t_fullmap		*parser(t_str mapfile);
t_ui			raytrace_editor(t_fullmap *map, t_vect ray);
t_3d_double		raytrace_loop(t_fullmap *map, t_vect ray, int depth);
t_3d_double		raytrace_fullrender(t_fullmap *map, t_vect ray);
void			full_render_init(t_str mapfile, t_fullmap *map);
void			full_render_from_edit(t_str mapfile, t_fullmap *map,
		t_sdl_bundle b, t_kp kp);
void			full_render_start(t_sdl_bundle b, t_fullmap *map,
		t_str mapfile);
void			full_render_threads(t_fullmap *map, t_sdl_bundle b);

Uint32			getpixel(SDL_Surface *img, int x, int y);

#endif

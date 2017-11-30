/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_prototypes_main.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:00:40 by nthibaud          #+#    #+#             */
/*   Updated: 2017/11/30 17:41:46 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PROTOTYPES_MAIN_H
# define RT_PROTOTYPES_MAIN_H

#include "rt.h"

/*
**	Main functions
*/
void			editor_start(t_str mapfile);
int				main(int ac, char **av);
t_fullmap		*parser(t_str mapfile);
t_ui			raytrace_editor(t_fullmap *map, t_vect ray);
t_ui			raytrace_fullrender(t_fullmap *map, t_vect ray);
void			render_options_win(t_fullmap *map);


void	full_render_init(t_str mapfile);
void	full_render_from_edit(t_str mapfile, t_fullmap *map, t_SDL_Bundle b, t_kp kp);
void full_render_start(t_SDL_Bundle b, t_fullmap *map, t_str mapfile);

Uint32			getpixel(SDL_Surface *img, int x, int y);

#endif

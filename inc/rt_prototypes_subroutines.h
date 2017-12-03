/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_prototypes_subroutines.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:02:51 by nthibaud          #+#    #+#             */
/*   Updated: 2017/12/01 16:24:16 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PROTOTYPES_SUBROUTINES_H
# define RT_PROTOTYPES_SUBROUTINES_H

#include "rt.h"

/*
**	Subroutines
*/
void			sub_basic_arg_test(int ac, char **av);
void			sub_blit_render(SDL_Surface *src, SDL_Surface *dest);
short			sub_check_extension(t_str file, t_str ext);
void			sub_create_file(t_str file) __attribute__((noreturn));
SDL_Window		*sub_create_render_window(t_str mapfile, int sx, int sy);
void			sub_create_xml(int fd);
void			sub_draw_image_editor(t_fullmap *map, SDL_Surface *img);
t_cam_vects		sub_calc_cam_vects(t_vect cam, int img_x, int img_y);
void			sub_fullrender_end(SDL_Window *win, SDL_Surface *img);
void			sub_handle_keyboard(t_kp kp, t_fullmap *map);
t_hit			sub_intersect_sphere(t_object *obj, t_vect ray);
t_ui			sub_texture_sphere(t_hit hit);
void			sub_mv_cdir_add(t_vect *cam, t_3d_double dir, double speed);
void			sub_mv_cdir_sub(t_vect *cam, t_3d_double dir, double speed);
void			sub_mv_cdir_up(t_vect *cam, t_3d_double dir, double speed);
void			sub_mv_cdir_down(t_vect *cam, t_3d_double dir, double speed);
void			sub_mv_cpos_add(t_vect *cam, t_3d_double dir, double speed);
void			sub_mv_cpos_sub(t_vect *cam, t_3d_double dir, double speed);
t_light			*sub_malloc_lights(t_fullmap *map, xmlNode *node);
t_object		*sub_malloc_objects(t_fullmap *map, xmlNode *node);
t_vect			*sub_malloc_cameras(t_fullmap *map, xmlNode *node);
void			sub_parser_xml(t_fullmap *map, xmlDoc *doc);
void			sub_put_fps(SDL_Surface **img, t_2dint *mapfps, SDL_Surface *w);
void			sub_put_text(SDL_Surface *img, t_str text);
void			sub_put_percent(SDL_Window *win, SDL_Surface *img, double val);
unsigned int	sub_read_hex(t_str str);
t_3d_double		sub_read_pos(t_str str);
t_3d_double		sub_read_dir(t_str str);
t_3d_double		sub_read_3d_double(t_str str);
double			sub_read_double(t_str str);
SDL_Surface		*sub_read_texture(t_str file);
void			sub_xml_read_light(t_light *light, xmlNode *node);
void			sub_xml_read_object(t_object *obj, xmlNode *node);
void			sub_xml_read_camera(t_vect *cam, xmlNode *node);

t_vect sub_calc_pix_vect(t_cam_vects cam, t_2dint pos, SDL_Surface *img);

/*
**	Intersections
*/
t_hit	sub_inter_objects(t_fullmap *map, t_vect ray);
t_hit	sub_inter_sphere(t_object *obj, t_vect ray);
t_hit	sub_inter_cone(t_object *cone, t_vect ray);
t_hit	sub_inter_plane(t_object *plane, t_vect ray);
t_hit	sub_inter_cylinder(t_object *cyl, t_vect ray);
t_hit	sub_inter_disk(t_object *disk, t_vect ray);

/*
**	Lights
*/
t_3d_double	sub_light_primary_ray(t_fullmap *map, t_hit hit, t_vect *ray);
#endif

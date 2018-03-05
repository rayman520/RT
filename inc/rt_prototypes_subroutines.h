/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_prototypes_subroutines.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:02:51 by nthibaud          #+#    #+#             */
/*   Updated: 2018/03/05 15:00:11 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PROTOTYPES_SUBROUTINES_H
# define RT_PROTOTYPES_SUBROUTINES_H

# include "rt.h"

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
t_ui			sub_texture_cone_cyl(t_hit hit);
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
t_obj_t			sub_read_filter(t_str str);
unsigned int	sub_read_hex(t_str str);
t_3d_double		sub_read_pos(t_str str);
t_3d_double		sub_read_dir(t_str str);
t_3d_double		sub_read_3d_double(t_str str);
double			sub_read_double(t_str str);
SDL_Surface		*sub_read_texture(t_str file);
void			sub_xml_read_light(t_light *light, xmlNode *node);
void			sub_xml_read_object(t_object *obj, xmlNode *node);
void			sub_xml_read_camera(t_vect *cam, xmlNode *node);
void			fresnel(t_vect ray, t_hit hit, double *refraction, double *kr);
t_3d_double		sub_texture_change(t_hit hit, t_fullmap *map);
double			noise3(double x, double y, double z, int *perlin_tab);
t_vect			sub_calc_pix_vect(t_cam_vects cam, t_2dint pos, int img_w,
		int img_h);
void			join_threads(pthread_t *threads, t_rend_zone *zone_tab,
		t_SDL_Bundle b);
void			create_threads(t_rend_zone *zone_tab, int i,
		pthread_t *threads);
char			*xmlngc(const xmlNode *cur);
void			default_object(t_object *obj, int o_nb);

/*
**	Intersections
*/
t_hit			sub_inter_objects(t_fullmap *map, t_vect ray);
t_hit			sub_inter_sphere(t_object *obj, t_vect ray);
t_hit			sub_inter_cone(t_object *cone, t_vect ray);
t_hit			sub_inter_plane(t_object *plane, t_vect ray);
t_hit			sub_inter_cylinder(t_object *cyl, t_vect ray);
t_hit			sub_inter_disk(t_object *disk, t_vect ray);
t_hit			sub_inter_triangle(t_object *triangle, t_vect ray);
t_hit			sub_inter_paraboloid(t_object *quad, t_vect ray);
t_hit			sub_inter_hyperboloid(t_object *cube, t_vect ray);

/*
**	Lights
*/
t_3d_double		sub_light_primary_ray(t_fullmap *map, t_hit hit,
		t_vect *ray, int depth);
t_3d_double		sub_light_compute_color(t_fullmap *map, t_hit hit,
		t_light light, t_vect *ray);
void			sub_perturb_normal(t_hit *hit, int *perlinmp);
t_3d_double		sub_refr(t_fullmap *map, t_hit hit, t_vect *ray, int depth);
t_3d_double		sub_reflection(t_fullmap *map, t_hit hit,
		t_vect *ray, int depth);
t_3d_double		rt_refract(t_vect ray, t_hit hit, double *refraction);
void			fresnel(t_vect ray, t_hit hit, double *refraction, double *kr);
#endif

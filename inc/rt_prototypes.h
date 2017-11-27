/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_prototypes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 10:20:50 by cpierre           #+#    #+#             */
/*   Updated: 2017/11/22 11:57:58 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PROTOTYPES_H
# define RT_PROTOTYPES_H

#include "rt.h"

/*
**	Basic
*/
int				ft_atoi(t_str str);
float			ft_biggest_fl(float a, float b);
void			ft_close_win(Uint32 id);
double			ft_descriminent(double a, double b, double c);
double			ft_dot_product(t_vect v1, t_vect v2);
int				ft_double_to_int(double nb);
int				ft_double_eq(double nb1, double nb2, double t);
void			ft_event_sdlquit(void) __attribute__((noreturn));
void			ft_exit(char *str) __attribute__((noreturn));
void			ft_handle_events(t_kp kp);
void			ft_handle_windowevent(SDL_WindowEvent win);
void			ft_hey(void);
size_t			ft_uintlen(unsigned int nb);
size_t			ft_intlen(int nb);
t_str			ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putpixel(SDL_Surface *img, t_2dint pos, Uint32 val);
void			ft_putstr(char *str);
int				ft_putunlckpixel(SDL_Surface *img, t_2dint pos, Uint32 val);
t_ui			ft_rgb_to_int(t_rgb color);
void			ft_str_replace(char *str, char target, char new);
t_str			ft_strcat(t_str dest, t_str src);
int				ft_strcmp(const char *s1, const char *s2);
t_str			ft_strcpy(t_str dst, t_str src);
t_str			ft_strdup(t_str src);
t_str			ft_strjoin(t_str s1, t_str s2);
size_t			ft_strlen(char *str);
t_str			ft_strrev(t_str str);
char			*ft_strupcase(char *str);
t_vect			ft_unit_vect(t_vect vect);
double			ft_vect_norm(t_vect vect);
t_2dint			ft_xml_ed_res(t_str input);
t_2dint			ft_xml_rd_res(t_str input);

/*
**	Vector handle
*/
t_3d_double		v_cross(t_3d_double a, t_3d_double b);
t_3d_double		v_div_by_nb(t_3d_double v, double nb);
t_3d_double		v_div_by_vv(t_3d_double a, t_3d_double b);
double			v_dot(t_3d_double a, t_3d_double b);
double			v_len(t_3d_double v);
t_3d_double		v_norm(t_3d_double v);
t_3d_double		v_mult_by_nb(t_3d_double v, double nb);
t_3d_double		v_mult_by_v(t_3d_double a, t_3d_double b);
t_3d_double		v_sub_a_by_b(t_3d_double a, t_3d_double b);
t_3d_double		v_sum(t_3d_double a, t_3d_double b);

/*
**	Matrix handle
*/

double			**m4_allocate(void);
void			m4_fill(double **m, t_m_rows m_rows);
double			**m4_mult_m4(double **m1, double **m2);
t_3d_double		m4_mult_v(double **m, t_3d_double v);
void			m_set_as_default(double **m);
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
/*
**	Main functions
*/
void			editor_start(t_str mapfile);
void			full_render_start(t_str mapfile);
int				main(int ac, char **av);
t_fullmap		*parser(t_str mapfile);
t_ui			raytrace_editor(t_fullmap *map, t_vect ray);
void			render_options_win(t_fullmap *map);

Uint32			getpixel(SDL_Surface *img, int x, int y);

#endif

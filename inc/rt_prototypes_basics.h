/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_prototypes_basics.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:01:39 by nthibaud          #+#    #+#             */
/*   Updated: 2017/12/05 17:43:29 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PROTOTYPES_BASICS_H
# define RT_PROTOTYPES_BASICS_H

# include "rt.h"

/*
**	Basics
*/
double			ft_flabs(float nb);
int				ft_atoi(t_str str);
float			ft_atof(t_str str);
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
int				ft_is_any_string(t_str str, int n, ...);
int				ft_isnbr(int c);
int				ft_isspace(int c);
t_str			ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putpixel(SDL_Surface *img, t_2dint pos, Uint32 val);
void			ft_putstr(char *str);
int				ft_putunlckpixel(SDL_Surface *img, t_2dint pos, Uint32 val);
t_ui			ft_rgb_to_int(t_rgb color);
t_ui			ft_double_3d_to_int(t_3d_double color);
t_3d_double		ft_int_to_double_3d(t_ui color);
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
float	        ft_fmax(float a, float b);
float	        ft_clamp(double a, double min, double max);
void			ft_doubleswap(double *d1, double *d2);
void			ft_vectorswap(t_3d_double *v1, t_3d_double *v2);
void			ft_floatswap(float *d1, float *d2);

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
void		    v_normalize(t_3d_double *v);

/*
**	Matrix handle
*/
double			**m4_allocate(void);
void			m4_fill(double **m, t_m_rows m_rows);
double			**m4_mult_m4(double **m1, double **m2);
t_3d_double		m4_mult_v(double **m, t_3d_double v);
void			m_set_as_default(double **m);

/*
**	Debug
*/
void			display_3d_double(char *s, t_3d_double v);
void			display_2d_int(char *s, t_2dint v);
void			display_vect(char *s, t_vect v);
void			display_cam_vects(char *s, t_cam_vects cam_v);

#endif

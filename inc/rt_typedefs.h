/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_typedefs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 13:15:49 by cpierre           #+#    #+#             */
/*   Updated: 2017/11/14 14:48:05 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TYPEDEFS_H
# define RT_TYPEDEFS_H

typedef char*	t_str;

typedef unsigned int t_ui;

typedef unsigned long t_ul;

typedef unsigned char t_uc;

typedef const char	t_cc;

typedef double	t_d;

typedef	short*	t_kp;

typedef struct	s_2dint
{
	int			x;
	int			y;
}				t_2dint;

typedef struct	s_3d_double
{
	double		x;
	double		y;
	double		z;
}				t_3d_double;

typedef	struct	s_rgb
{
	int			b;
	int			g;
	int			r;
}				t_rgb;

typedef	struct	s_vect
{
	t_3d_double pos;
	t_3d_double dir;
}				t_vect;

typedef struct	s_cam_vects
{
	t_vect		start;
	t_vect		right;
	t_vect		down;
	double		fov;
}				t_cam_vects;

typedef struct	s_light
{
	t_3d_double	pos;
	double		pow;
}				t_light;

typedef enum	e_obj_t
{
	SPHERE = 1,
}				t_obj_t;

typedef struct	s_object
{
	t_3d_double	pos;
	t_obj_t		type;
	t_ui		color;
	double		radius;
	SDL_Surface *texture;
}				t_object;

typedef	struct	s_hit
{
	t_3d_double pos;
	t_3d_double	normal_dir;
	t_vect		incident_vect;
	t_object	*obj;
	double		dist;
}				t_hit;

typedef struct	s_SDL_Bundle
{
	SDL_Window	*render_win;
	SDL_Surface *window_img;
	SDL_Surface *render_img;
}				t_SDL_Bundle;

typedef struct	s_fullmap
{
	t_light		*light;
	t_object	*obj;
	t_vect		*camera;
	t_2dint		res;
	t_2dint		editres;
	t_2dint		fps;
	t_str		mapfile_pathname;
	t_cam_vects	cam_v;
	int			light_c;
	int			obj_c;
	int			cam_c;
	int			target_cam;
	double		amb_coef;
	double		fov;
}				t_fullmap;

typedef t_hit	(*t_isect_fnc_tab[1])(t_object *obj, t_vect ray);
typedef	t_ui	(*t_texture_ft_tab[1])(t_hit hit);

#endif

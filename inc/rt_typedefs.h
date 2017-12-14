/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_typedefs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 13:15:49 by cpierre           #+#    #+#             */
/*   Updated: 2017/12/11 12:29:41 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_TYPEDEFS_H
# define RT_TYPEDEFS_H

#include "rt.h"

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

typedef struct	s_m_rows
{
	t_3d_double	x_row;
	t_3d_double	y_row;
	t_3d_double	z_row;
	t_3d_double	w_row;
}				t_m_rows;

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
	t_3d_double	ndir;
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
	double		intensity;
	t_3d_double	color;
	t_vect		ray;
	double		bias;
}				t_light;

typedef enum	e_obj_t
{
	SPHERE = 1,
	CONE = 2,
	CYLINDER = 3,
	PLANE = 4,
	DISK = 5,
}				t_obj_t;

typedef struct		s_inter
{
	double			a;
	double			b;
	double			c;
	double			discr;
	double			t0;
	double			t1;
	t_3d_double		dist;
	t_3d_double		temp;
	t_3d_double		norm;
	t_3d_double		temp2;
}					t_inter;

typedef struct		s_triter
{
	double 			det;
	double 			invdet;
	t_3d_double 	edge1;
	t_3d_double 	edge2;
	t_3d_double 	vs1;
	t_3d_double 	vs2;
	t_3d_double 	vs3;
	double 			tmp;
	double 			u;
	double			v;
}					t_triter;

typedef struct		s_refra
{
	float 			cosi;
	float 			cost;
	float			sint;
	float 			etai;
	float 			eta;
	float 			etat;
	float 			k;
	float			rs;
	float			rp;
	t_3d_double 	tmpdir;
	t_3d_double 	tmpnorm;
	t_3d_double 	refranorm;
}					t_refra;

typedef struct		s_frafle
{
	t_3d_double 	refranorm;
	int				outside;
	double			reflect;
	t_3d_double		tmp;
	t_vect			refleray;
	t_vect			refraray;
	t_3d_double		refracolor;
	t_3d_double		reflecolor;
	t_3d_double 	bias;
	double			kr;
}					t_frafle;

typedef struct	s_object
{
	t_3d_double	pos;
	t_3d_double	dir;
	t_3d_double	rgb_color;
	t_3d_double min;
	t_3d_double max;
	t_3d_double pa;
	t_3d_double pb;
	t_3d_double pc;
	t_3d_double pd;
	t_obj_t		type;
	int			material;
	int			negative;
	int			noise;
	double		reflection;
	double		refraction;
	double		refracoef;
	t_ui		color;
	double		radius;
	double		albedo;
	SDL_Surface *texture;
	int			texture_type;
	double		bump;
	int			i;
}				t_object;

typedef	struct	s_hit
{
	t_3d_double pos;
	t_3d_double pos2;
	t_3d_double	normal_dir;
	t_vect		incident_vect;
	t_object	*obj;
	double		dist;
	double		dist2;
	int			is_hit;
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
	double		coef;
	t_2dint		editres;
	t_2dint		fps;
	t_str		mapfile_pathname;
	t_cam_vects	cam_v;
	int			light_c;
	int			obj_c;
	int			cam_c;
	int			target_cam;
	int			filter;
	double		amb_coef;
	double		fov;
	int			render_key;
	int			maxdepth;
	double		shadowcoef;
}				t_fullmap;

typedef struct	s_noise
{
	int 		tab[512];
	int 		cx;
	int 		cy;
	int 		cz;
	double 		u;
	double 		v;
	double 		w;
	int 		a;
	int 		b;
	int 		aa;
	int 		ab;
	int 		bb;
	int 		ba;
}				t_noise;

typedef t_hit	(*t_isect_fnc_tab[5])(t_object *obj, t_vect ray);
typedef	t_ui	(*t_texture_ft_tab[1])(t_hit hit);

#endif

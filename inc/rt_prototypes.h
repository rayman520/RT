/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_prototypes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 10:20:50 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/27 18:01:25 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PROTOTYPES_H
# define RT_PROTOTYPES_H

/*
**	Basic
*/
int				ft_atoi(t_str str);
float			ft_biggest_fl(float a, float b);
void			ft_close_win(Uint32 id);
void			ft_event_sdlquit(void) __attribute__((noreturn));
void			ft_exit(char *str) __attribute__((noreturn));
void			ft_handle_events(void);
void			ft_handle_windowevent(SDL_WindowEvent win);
void			ft_hey(void);
size_t			ft_uintlen(unsigned int nb);
size_t			ft_intlen(int nb);
t_str			ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putpixel(SDL_Surface *img, t_2dint pos, Uint32 val);
void			ft_putstr(char *str);
int				ft_putunlckpixel(SDL_Surface *img, t_2dint pos, Uint32 val);
t_str			ft_strcat(t_str dest, t_str src);
int				ft_strcmp(const char *s1, const char *s2);
t_str			ft_strcpy(t_str dst, t_str src);
t_str			ft_strdup(t_str src);
t_str			ft_strjoin(t_str s1, t_str s2);
size_t			ft_strlen(char *str);
t_str			ft_strrev(t_str str);
char			*ft_strupcase(char *str);
t_2dint			ft_xml_rd_res(t_str input);

/*
**	Subroutines
*/
void			sub_basic_arg_test(int ac, char **av);
void			sub_blit_render(SDL_Surface *src, SDL_Surface *dest);
short			sub_check_extension(t_str file, t_str ext);
void			sub_create_file(t_str file) __attribute__((noreturn));
SDL_Window		*sub_create_render_window(t_str mapfile);
void			sub_create_xml(int fd);
void			sub_fullrender_end(SDL_Window *win, SDL_Surface *img);
t_light			*sub_malloc_lights(t_fullmap *map, xmlNode *node);
t_object		*sub_malloc_objects(t_fullmap *map, xmlNode *node);
void			sub_parser_xml(t_fullmap *map, xmlDoc *doc);
void			sub_put_percent(SDL_Window *win, SDL_Surface *img, double val);
t_3d_double		sub_read_pos(t_str str);
double			sub_read_double(t_str str);
void			sub_xml_read_light(t_light *light, xmlNode *node);
void			sub_xml_read_object(t_object *obj, xmlNode *node);
/*
**	Main functions
*/
void			editor_start(t_str mapfile);
void			full_render_start(t_str mapfile);
int				main(int ac, char **av);
t_fullmap		*parser(t_str mapfile);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_prototypes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 10:20:50 by cpierre           #+#    #+#             */
/*   Updated: 2017/09/11 16:37:21 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PROTOTYPES_H
# define RT_PROTOTYPES_H

/*
**	Basic
*/
float			ft_biggest_fl(float a, float b);
void			ft_close_win(Uint32 id);
void			ft_event_sdlquit(void) __attribute__((noreturn));
void			ft_exit(char *str) __attribute__((noreturn));
void			ft_handle_events(void);
void			ft_handle_windowevent(SDL_WindowEvent win);
void			ft_hey(void);
void			ft_putchar(char c);
void			ft_putpixel(SDL_Surface *img, t_2dint pos, Uint32 val);
void			ft_putstr(char *str);
int				ft_putunlckpixel(SDL_Surface *img, t_2dint pos, Uint32 val);
t_str			ft_strcat(t_str dest, t_str src);
int				ft_strcmp(char *s1, char *s2);
t_str			ft_strcpy(t_str dst, t_str src);
t_str			ft_strdup(t_str src);
t_str			ft_strjoin(t_str s1, t_str s2);
size_t			ft_strlen(char *str);
t_str			ft_strrev(t_str str);
char			*ft_strupcase(char *str);

/*
**	Subroutines
*/
void			sub_basic_arg_test(int ac, char **av);
void			sub_blit_render(SDL_Surface *src, SDL_Surface *dest);
short			sub_check_extension(t_str file, t_str ext);
void			sub_create_file(t_str file) __attribute__((noreturn));
SDL_Window		*sub_create_render_window(t_str mapfile);
/*
**	Main functions
*/
void			full_render_start(t_str mapfile);
int				main(int ac, char **av);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_prototypes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 10:20:50 by cpierre           #+#    #+#             */
/*   Updated: 2017/08/28 14:58:13 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PROTOTYPES_H
# define RT_PROTOTYPES_H

/*
**	Basic
*/
void			ft_exit(char *str) __attribute__((noreturn));
void			ft_hey(void);
void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_strcmp(char *s1, char *s2);
t_str			ft_strcpy(t_str dst, t_str src);
t_str			ft_strdup(t_str src);
size_t			ft_strlen(char *str);
t_str			ft_strrev(t_str str);
char			*ft_strupcase(char *str);

/*
**	Subroutines
*/
void			ft_basic_arg_test(int ac, char **av);
int				ft_check_extension(t_str file, t_str ext);

int				main(int ac, char **av);

#endif

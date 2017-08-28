/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_prototypes.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 10:20:50 by cpierre           #+#    #+#             */
/*   Updated: 2017/08/28 11:52:41 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_PROTOTYPES_H
# define RT_PROTOTYPES_H

/*
**	Basic
*/
void			ft_exit(char *str) __attribute__((noreturn));
void			ft_putchar(char c);

/*
**	Subroutines
*/
void			ft_basic_arg_test(int ac, char **av);
int				main(int ac, char **av);

#endif

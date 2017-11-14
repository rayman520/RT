/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_defines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 11:20:08 by cpierre           #+#    #+#             */
/*   Updated: 2017/11/14 12:41:04 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_DEFINES_H
# define RT_DEFINES_H

# define EDITOR_IMG_WIDTH 640
# define EDITOR_IMG_HEIGHT 480

# define EDITOR_WIN_WIDTH 990
# define EDITOR_WIN_HEIGHT 850

# define RENDER_WIN_WIDTH 1280
# define RENDER_WIN_HEIGHT 800

# define OPT_WIN_W 400
# define OPT_WIN_H 850

# define NULL_POS (t_3d_double){0, 0, 0}
# define NULL_VECT (t_vect){NULL_POS, NULL_POS}
# define NULL_HIT (t_hit){NULL_POS, NULL_POS, NULL_VECT, NULL, -1}

# define RENDER_DIST 1000000000

# define ERR_USAGE "usage: ./rt mode file\n  mode: render/edit/create"

# define HEY ft_hey();

# define CRST	"\x1B[0m"
# define CRED	"\x1B[31m"
# define CGRN	"\x1B[32m"
# define CYEL	"\x1B[33m"
# define CBLU	"\x1B[34m"
# define CMAG	"\x1B[35m"
# define CCYN	"\x1B[36m"
# define CLGRY	"\x1B[37m"
# define CGRY	"\x1B[90m"
# define CLRED	"\x1B[91m"
# define CLGRN	"\x1B[92m"
# define CLYEL	"\x1B[93m"
# define CLBLU	"\x1B[94m"
# define CLMAG	"\x1B[95m"
# define CLCYN	"\x1B[96m"
# define CWHT	"\x1B[97m"

# define IMGINITFLAGS (IMG_INIT_JPG)

#endif

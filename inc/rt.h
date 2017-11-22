/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 10:15:23 by cpierre           #+#    #+#             */
/*   Updated: 2017/11/22 12:08:56 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <pthread.h>
# include <signal.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# include <../lib/frameworks/SDL2.framework/Headers/SDL.h>
# include <../lib/frameworks/SDL2_image.framework/Headers/SDL_image.h>
# include <../lib/frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h>

# include <libxml2/libxml/parser.h>

# include "rt_typedefs.h"
# include "rt_defines.h"
# include "rt_prototypes_main.h"
# include "rt_prototypes_basics.h"
# include "rt_prototypes_subroutines.h"

#endif

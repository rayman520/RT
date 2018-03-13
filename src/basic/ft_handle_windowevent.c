/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_windowevent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:30:37 by cpierre           #+#    #+#             */
/*   Updated: 2018/03/13 13:11:32 by nthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	handle_windowevent2(SDL_WindowEvent win)
{
	if (win.event == SDL_WINDOWEVENT_RESTORED)
		ft_putstr("Window restored\n");
	else if (win.event == SDL_WINDOWEVENT_ENTER)
		ft_putstr("Mouse entered window\n");
	else if (win.event == SDL_WINDOWEVENT_LEAVE)
		ft_putstr("Mouse left window\n");
	else if (win.event == SDL_WINDOWEVENT_FOCUS_GAINED)
		ft_putstr("Window gained keyboard focus\n");
	else if (win.event == SDL_WINDOWEVENT_FOCUS_LOST)
		ft_putstr("Window lost keyboard focus\n");
	else if (win.event == SDL_WINDOWEVENT_CLOSE)
		ft_close_win(win.windowID);
	else if (win.event == SDL_WINDOWEVENT_TAKE_FOCUS)
		ft_putstr("Window is offered a focus\n");
	else if (win.event == SDL_WINDOWEVENT_HIT_TEST)
		ft_putstr("Window has a special hit test\n");
	else
		ft_putstr("Window got unknown event \n");
}

void		ft_handle_windowevent(SDL_WindowEvent win)
{
	if (win.event == SDL_WINDOWEVENT_SHOWN)
		ft_putstr("Window shown\n");
	else if (win.event == SDL_WINDOWEVENT_HIDDEN)
		ft_putstr("Window hidden\n");
	else if (win.event == SDL_WINDOWEVENT_EXPOSED)
		ft_putstr("Window exposed\n");
	else if (win.event == SDL_WINDOWEVENT_MOVED)
		ft_putstr("Window moved to\n");
	else if (win.event == SDL_WINDOWEVENT_RESIZED)
		ft_putstr("Window resized to\n");
	else if (win.event == SDL_WINDOWEVENT_SIZE_CHANGED)
		ft_putstr("Window size changed to\n");
	else if (win.event == SDL_WINDOWEVENT_MINIMIZED)
		ft_putstr("Window minimized\n");
	else if (win.event == SDL_WINDOWEVENT_MAXIMIZED)
		ft_putstr("Window maximized\n");
	else
		handle_windowevent2(win);
}

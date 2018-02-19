/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_windowevent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 17:30:37 by cpierre           #+#    #+#             */
/*   Updated: 2018/02/19 17:23:12 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	handle_windowevent2(SDL_WindowEvent win)
{
	if (win.event == SDL_WINDOWEVENT_RESTORED)
		printf("Window %d restored\n", win.windowID);
	else if (win.event == SDL_WINDOWEVENT_ENTER)
		printf("Mouse entered window %d\n", win.windowID);
	else if (win.event == SDL_WINDOWEVENT_LEAVE)
		printf("Mouse left window %d\n", win.windowID);
	else if (win.event == SDL_WINDOWEVENT_FOCUS_GAINED)
		printf("Window %d gained keyboard focus\n", win.windowID);
	else if (win.event == SDL_WINDOWEVENT_FOCUS_LOST)
		printf("Window %d lost keyboard focus\n", win.windowID);
	else if (win.event == SDL_WINDOWEVENT_CLOSE)
		ft_close_win(win.windowID);
	else if (win.event == SDL_WINDOWEVENT_TAKE_FOCUS)
		printf("Window %d is offered a focus\n", win.windowID);
	else if (win.event == SDL_WINDOWEVENT_HIT_TEST)
		printf("Window %d has a special hit test\n", win.windowID);
	else
		printf("Window %d got unknown event %d\n", win.windowID, win.event);
}

void		ft_handle_windowevent(SDL_WindowEvent win)
{
	if (win.event == SDL_WINDOWEVENT_SHOWN)
		printf("Window %d shown\n", win.windowID);
	else if (win.event == SDL_WINDOWEVENT_HIDDEN)
		printf("Window %d hidden\n", win.windowID);
	else if (win.event == SDL_WINDOWEVENT_EXPOSED)
		printf("Window %d exposed\n", win.windowID);
	else if (win.event == SDL_WINDOWEVENT_MOVED)
		printf("Window %d moved to %d,%d\n", win.windowID,
			win.data1, win.data2);
	else if (win.event == SDL_WINDOWEVENT_RESIZED)
		printf("Window %d resized to %dx%d\n", win.windowID,
			win.data1, win.data2);
	else if (win.event == SDL_WINDOWEVENT_SIZE_CHANGED)
		printf("Window %d size changed to %dx%d\n", win.windowID,
			win.data1, win.data2);
	else if (win.event == SDL_WINDOWEVENT_MINIMIZED)
		printf("Window %d minimized\n", win.windowID);
	else if (win.event == SDL_WINDOWEVENT_MAXIMIZED)
		printf("Window %d maximized\n", win.windowID);
	else
		handle_windowevent2(win);
}

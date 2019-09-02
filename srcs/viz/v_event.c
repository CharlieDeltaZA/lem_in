/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_event.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 13:03:28 by cdiogo            #+#    #+#             */
/*   Updated: 2019/09/02 12:46:29 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/viz.h"

void		event_check(t_viz *viz, t_moves *moves)
{
	SDL_Event	event;

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_Quit)
			viz->close = 1;
		if (event.key.keysym.scancode == SDL_SCANCODE_Q)
			viz->close = 1;
		if (event.key.keysym.scancode == SDL_SCANCODE_SPACE)
		{
			//Move ants when space is pressed.
		}
	}
}

void		event_loop(t_viz *viz, t_rooms *info, t_moves *moves)
{
	//TODO
	while (!(viz->close))
	{
		//stuff
		ft_putendl("Hello!");
		check_event(viz, moves);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_drawing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:21:56 by cdiogo            #+#    #+#             */
/*   Updated: 2019/09/09 08:34:33 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/viz.h"

/*
** Draws the links between rooms
*/

void		draw_links(t_viz *viz, t_rooms *info)
{
	//linked to Cameron's struct atm
	t_room	*room;
	t_room	*room2;

	room = *info;
	while (room)
	{
		while (room->links)
		{
			room2 = find_room(room, room->links->link);
			thickLineColor(viz->rend, (room->pos.x + (ROOM_W/2)), (room->pos.y + (ROOM_H/2)), (room2->pos.x + (ROOM_W/2)), (room2->pos.y + (ROOM_H/2)), 8, 0xFFFFFF00);
			room->links = room->links->next;
		}
		// info = info->next;
		room = room->next;
	}
	ft_putendl("Holy cow this worked!");
}

/*
** Draws the rooms
*/

void		draw_rooms(t_viz *viz, t_rooms *info)
{
	//linked to Cameron's struct atm
	t_room		*room;
	SDL_Rect	dimension;

	dimension.w = ROOM_W;
	dimension.h = ROOM_H;
	room = *info;
	while (room)
	{
		dimension.x = room->pos.x + (ROOM_W / 2);
		dimension.y = room->pos.y + (ROOM_H / 2);
		if (room->type == 1)
			SDL_RenderCopy(viz->rend, viz->room)
		room = room->next;
	}
}

/*
** Draws the ants prior to the moves, and after each move
*/

void		draw_ants(t_viz *viz, t_rooms *info)
{
	
}

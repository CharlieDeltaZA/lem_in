/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_drawing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:21:56 by cdiogo            #+#    #+#             */
/*   Updated: 2019/09/04 18:38:05 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/viz.h"

/*
** Draws the links between rooms
*/

void		draw_links(t_viz *viz, t_rooms *info)
{
	t_rooms	*room1;
	t_rooms *room2;

	while (info)
	{
		room1 = info;
		while (info->links)
		{
			
		}
		info = info->next;
	}
}

/*
** Draws the rooms
*/

void		draw_rooms(t_viz *viz, t_rooms *info)
{

}

/*
** Draws the ants prior to the moves, and after each move
*/

void		draw_ants(t_viz *viz, t_rooms *info)
{
	
}

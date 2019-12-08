/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 09:10:12 by cdiogo            #+#    #+#             */
/*   Updated: 2019/12/08 15:42:22 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <lem_in2.h>
#include "../../includes/lem_in2.h"
#include "../../includes/viz.h"
// #include <viz.h>

int			map_count(void)
{
	static int	i = -1;

	i++;
	return (i);
}

int			main(void)
{
	char			*mappy[MAP_MAX];
	t_room			*rooms;
	t_viz			*visualizer;
	t_moves			*moves;
	t_ants			*ant;

	ant = NULL;
	moves = NULL;
	v_populate_map(mappy, &rooms, &moves);
	room_swap(&rooms);
	set_ants(mappy, &rooms);
	visualizer = init_viz();
	populate_viz(visualizer, &moves);
	ant = populate_ants(&rooms, &ant);
	event_loop(visualizer, &rooms, &moves, &ant);
	viz_free(&visualizer);
	moves_free(&moves);
	ants_free(&ant);
	free_rooms(&rooms);
	return (0);
}

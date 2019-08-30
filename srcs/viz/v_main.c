/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 09:10:12 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/30 16:36:37 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/viz.h"

int		main(void)
{
	t_viz	*visualizer;
	//TODO
	//read in from GNL (read until empty line, then set a bool to false to change the struct being written to?)
	read_info();
	//init the viz struct
	visualizer = init_viz();
	//allocate/populate to the viz struct
	populate_viz(visualizer);
	//draw links
	draw_links();
	//draw rooms
	draw_rooms();
	//draw ants
	draw_ants();
	//event loop (space to move through the turns)
	event_loop(visualizer);
	//free & close upon completion
	viz_free(&visualizer);
}

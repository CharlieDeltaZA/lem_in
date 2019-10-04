/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:19:08 by cdiogo            #+#    #+#             */
/*   Updated: 2019/10/04 23:52:22 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	bigboy_algo(t_rooms **room_head)
{
	// need to have a func that checks if a room is occupied. --Add a bool to struct?

	if (path_find(room_head))
		return ;
		//generate_moves(room_head);
	else
		free_rooms_error(room_head, PATH_ERROR);
}

int		main(void)
{
	// must display input, empty line, then moves

	t_rooms	*rooms;

	rooms = read_map();
	print_rooms(&rooms); 		// debug purposes
	bigboy_algo(&rooms);
	print_rooms(&rooms);		//debug purposes
	free_rooms(&rooms);
	//while(1);					//tests for leaks at the end
	return (0);
}

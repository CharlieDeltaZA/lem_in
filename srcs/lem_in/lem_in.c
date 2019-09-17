/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:19:08 by cdiogo            #+#    #+#             */
/*   Updated: 2019/09/17 12:19:26 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		main(int ac, char **av)
{
	// need to have a func that checks if a room is occupied. --Add a bool to struct?
	// must display input, empty line, then moves

	t_rooms	*rooms;
	t_links	*links;

	av = av + 1;				//check for other types of input??
	rooms = read_map();
	ft_putstr("\n\n");			// debug purposes
	print_rooms(&rooms); 		// debug purposes
	ft_putendl("");
	//bigboy_algo(&rooms);
	free_rooms(&rooms);
	while(1);					//tests for leaks
	return (0);
}

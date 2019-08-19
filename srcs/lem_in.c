/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:19:08 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/19 16:19:45 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

//TODO :)
int		main(int ac, char **av)
{
	// lots of error checking
	// input, room validation (Names won't start with '#' or 'L'), link validation
	// ignore # comments, accept ## commands (valid ones, so 'start' and 'end')
	// need to have a func that checks if a room is occupied. --Add a bool to struct?
	// init the stack of rooms - need a struct
	// gnl to read input from a file?
	// must display input, empty line, then moves
	// ^^ Input = num ants, ##commands, rooms, links
	if (ac > 1)
		{
			ft_putendl_fd("Too many args, uhm. HOW DO I HANDLE THIS?", 1);
			return (0);
		}
	read_map();
	// ??? Run the algo that does things and stuff
	return (0);
}

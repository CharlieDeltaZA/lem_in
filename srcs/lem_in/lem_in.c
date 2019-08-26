/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 16:19:08 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/26 09:59:27 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

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
		error_out(BAD_INPUT);
	av += 1;
	read_map();
	ft_putendl("");
	ft_putendl_col_fd(YELLOW, "Algo Things Here", 1);

	//ALGO_FUNC_HERE
	// ??? Run the algo that does things and stuff
	//while(1); //tests for leaks
	return (0);
}

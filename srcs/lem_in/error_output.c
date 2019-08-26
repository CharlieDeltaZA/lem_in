/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:43:46 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/26 09:59:44 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	error_out(int code)
{
	if (code == NO_ANTS)
		ft_putendl_col_fd(RED, "ERROR : No ants provided", 2);
	if (code == DUP_ROOM)
		ft_putendl_col_fd(RED, "ERROR : Duplicate Room names", 2);
	if (code == DUP_LINK)
		ft_putendl_col_fd(RED, "ERROR : Duplicate Links", 2);
	if (code == NO_START)
		ft_putendl_col_fd(RED, "ERROR : No Start Room found", 2);
	if (code == NO_END)
		ft_putendl_col_fd(RED, "ERROR : No End Room found", 2);
	if (code == BAD_INPUT)
		ft_putendl_col_fd(WHITE, "usage: ./lem-in < [path/to/map]", 2);
		// ft_putendl_col_fd(RED, "ERROR : Bad Input", 2);
	if (code == BAD_COMMAND)
		ft_putendl_col_fd(RED, "ERROR : Bad Command", 2);
	if (code == EMPTY_LINE)
		ft_putendl_col_fd(RED, "ERROR : Empty Line", 2);
	exit(1);
}

// Pass in things to free, and the error enum
void	free_and_error(int msg)
{
	//Free things and then error out with msg
	error_out(msg);
}

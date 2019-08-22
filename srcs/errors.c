/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:43:46 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/22 10:51:31 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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
		ft_putendl_col_fd(RED, "ERROR : Bad Input", 2);
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 09:46:46 by cdiogo            #+#    #+#             */
/*   Updated: 2019/12/08 15:42:10 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/viz.h"
// #include <viz.h>

/*
** Resets the ants to the start room and ensures the move list is back
** at the beginning.
*/

void	reset_moves(t_moves *moves, t_ants **ants, t_room **info, t_viz *viz)
{
	t_ants	*tmp;

	tmp = *ants;
	viz->curr_turn = moves;
	while (tmp)
	{
		tmp->current = *info;
		tmp->previous = NULL;
		tmp = tmp->next;
	}
	draw_master(viz, ants, info);
	ft_putendl_col_fd(CYAN, "Moves Reset!", 1);
}

/*
** Parses and executes a single turn for each keypress.
*/

void	parse_move(t_ants **ants, t_room **info, t_viz *viz)
{
	int		i;
	int		len_id;
	char	*ant_id;
	char	*r_name;

	if (viz->curr_turn)
	{
		i = 0;
		while (viz->curr_turn->move[i])
		{
			ft_putendl_col_fd(GREEN, viz->curr_turn->move[i], 1);
			len_id = id_length(viz->curr_turn->move[i]);
			ant_id = ft_strnew(len_id);
			while ((len_id - 1) >= 0)
			{
				ant_id[len_id - 1] = viz->curr_turn->move[i][len_id - 1];
				len_id--;
			}
			R_NAME;
			update_ant(ants, ant_id, r_name, info);
			free(ant_id);
			ft_putendl_col_fd(MAGENTA, "^^^ Complete", 1);
			i++;
		}
		if (viz->curr_turn)
			viz->curr_turn = viz->curr_turn->next;
	}
	ft_putendl_col_fd(YELLOW, "Moves Parsed!", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_disp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <cdiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 11:01:33 by bmarks            #+#    #+#             */
/*   Updated: 2020/01/06 14:19:17 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in2.h"

void		disp_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		free(map[i]);
		i++;
	}
	ft_putstr("\n");
}

static void	insfn(t_ant *ant)
{
	ft_putchar('L');
	ft_putnbr(ant->ant_num);
	ft_putchar('-');
	ant->path = ant->path->next_room;
	ant->curr_room = ant->path->room_name;
}

void		disp_ants(t_ant *ant, t_room **rooms)
{
	t_room	*tmp;

	tmp = *rooms;
	while (tmp && tmp->type != 2)
		tmp = tmp->next;
	if (!ft_strequ(ant->curr_room, tmp->name))
	{
		tmp = *rooms;
		while (!ft_strequ(tmp->name, ant->path->next_room->room_name))
			tmp = tmp->next;
		if (tmp->ant_count == 0 || tmp->type == 2)
		{
			tmp = *rooms;
			while (!ft_strequ(tmp->name, ant->curr_room))
				tmp = tmp->next;
			tmp->ant_count -= 1;
			insfn(ant);
			tmp = *rooms;
			while (!ft_strequ(tmp->name, ant->curr_room))
				tmp = tmp->next;
			tmp->ant_count += 1;
			ft_putstr(ant->curr_room);
			ft_putchar(' ');
		}
	}
}

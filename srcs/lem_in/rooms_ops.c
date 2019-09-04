/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:20:31 by cdiogo            #+#    #+#             */
/*   Updated: 2019/09/03 13:43:39 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static t_rooms		*create_node(char *line)
{
	t_rooms	*node;

	node = (t_rooms*)malloc(sizeof(t_rooms));
	if (node)
	{
		//node->name = ft_strdup(line);
		node->name = "help";		//get_name(line); //combine these 3 get funcs into 1?
		node->x = 0;				//get_x(line);
		node->y = 0;				//get_y(line);
		node->start = 0;			//something to check for an activated bit
		node->end = 0;				//something to check for an activated bit
		// links???
		node->next = NULL;
	}
	return (node);
}

static void			add_tail(t_rooms **head, t_rooms *node)
{
	t_rooms	*tmp;

	if (!(head) || (!(node)))
		return ;
	tmp = *head;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

t_rooms		*init_rooms(t_rooms **head, char *s, int val)
{
	//loop through temp. Once a room line is found add it to rooms
	//do this until the end of temp.
	//Also check if ##start OR ##end flag = 1(start) OR flag = 2(end). The next looped line must be set active as start or end.
	//otherwise the end and start bool remains 0 in the struct.
}
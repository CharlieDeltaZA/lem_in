/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:20:31 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/26 09:59:51 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

// Ops for t_rooms
static t_rooms		*create_node(char *line)
{
	//TODO
	t_rooms	*node;

	node = (t_rooms*)malloc(sizeof(t_rooms));
	if (node)
	{
		// node->name = ft_strdup(line);
		node->name = "help";//get_name(line); //combine these 3 get funcs into 1?
		node->x = 0;//get_x(line);
		node->y = 0;//get_y(line);
		node->start = 0; //something to check for an activated bit
		node->end = 0; //something to check for an activated bit
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

void				free_rooms(t_rooms **head)
{
	t_rooms	*current;
	t_rooms	*next;

	current = *head;
	while (current)
	{
		next = current->next;
		free(current->name);
		free(current);
		current = next;
	}
	*head = NULL;
}

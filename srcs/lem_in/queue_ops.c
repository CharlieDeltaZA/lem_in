/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:55:29 by jhansen           #+#    #+#             */
/*   Updated: 2019/09/19 16:16:17 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static void		add_tail(t_queue **head, t_queue *node)
{
	t_queue	*temp;

	if (!(head) || (!(node)))
		return ;
	if (*head)
	{
		temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
}

static t_queue	*create_node(t_rooms *room)
{
	t_queue	*node;

	node = (t_queue *)malloc(sizeof(t_queue));
	if (node)
	{
		node->room = room;
		node->explored = 0;
		node->next = NULL;
	}
	return (node);
}

void			queue_links(t_queue **queue, t_rooms *rooms)
{
	t_queue	*node;
	t_links	*link;

	link = NULL;
	if (rooms->links)
	{
		link = rooms->links;
		while (link != NULL)
		{
			if (*queue)
			{
				node = create_node(rooms);
				add_tail(queue, node);
			}
			else
				*queue = create_node(rooms);
			link = link->next;
		}
	}
}

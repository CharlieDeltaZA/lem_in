/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:55:29 by jhansen           #+#    #+#             */
/*   Updated: 2019/10/03 00:40:01 by jhansen          ###   ########.fr       */
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

static t_queue	*create_node(t_rooms *room, int weight)
{
	t_queue	*node;

	node = (t_queue *)malloc(sizeof(t_queue));
	if (node)
	{
		node->room = room;
		node->explored = 0;
		node->weight = weight + 1;
		node->next = NULL;
	}
	return (node);
}

int				already_queued(t_queue **queue, char *room_name)
{
	t_queue	*temp;

	temp = *queue;
	if (temp)
	{
		while (temp != NULL)
		{
			if (ft_strequ(temp->room->name, room_name))
			{
				ft_putstr_col_fd(RED, "DUPLICATE FOUND\n", 1);		//
				return (1);
			}
			ft_putstr_col_fd(RED, "Non duplicate\n", 1);			//
			temp = temp->next;
		}
	}
	return (0);
}

void		queue_start(t_queue **queue, t_rooms **start)
{
	if (*start)
		*queue = create_node(*start, 0);
	else
		ft_putstr_col_fd(RED, "WTF a queue already?\n", 1);		//
}

void			queue_links(t_queue **queue, t_rooms **curr_room)
{
	t_queue	*node;
	t_rooms	*room;

	room = *curr_room;
	if (room && room->links)
	{
		while (room->links != NULL)
		{
			if (already_queued(queue, room->links->room) == 0)
			{
				if (*queue)
				{
					node = create_node(room, room->weight);
					add_tail(queue, node);
				}
				else
					*queue = create_node(room, room->weight);
			}
			room->links = room->links->next;
		}
	}
}

t_rooms		*next_link(t_queue **queue)
{
	t_queue	*temp;

	temp = *queue;
	if (temp)
	{
		while (temp != NULL)
		{
			if (temp->explored == 0)
			{
				temp->explored = 1;
				return (temp->room);
			}
			temp = temp->next;
		}
	}
	return (NULL);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:20:31 by cdiogo            #+#    #+#             */
/*   Updated: 2019/09/04 18:49:30 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static t_rooms		*create_node(char *line, int xcoord, int ycoord, int val)
{
	t_rooms	*node;

	node = (t_rooms*)malloc(sizeof(t_rooms));
	if (node)
	{
		node->name = line;
		node->x = xcoord;
		node->y = ycoord;
		if (val == 1)
		{
			node->start = 1;
			node->end = 0;
		}
		else if (val == 2)
		{
			node->start = 0;
			node->end = 1;			
		}
		else
		{
			node->start = 0;
			node->end = 0;			
		}
		// links?
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
	t_rooms	*node;
	char	**arr;
	int		x;
	int		y;

	arr = ft_strsplit(s, ' ');
	x = ft_atol(arr[1]);
	y = ft_atol(arr[2]);
	if (*head)
	{
		node = create_node(arr[0], x, y, val);
		add_tail(head, node);
	}
	else
		*head = create_node(arr[0], x, y, val);
	return (*head);
}

void		print_rooms(t_rooms **head)
{
	t_rooms	*temp;

	temp = *head;
	if (temp)
	{
		while (temp->next != NULL)
		{
			printf("NAME:  %s\n", temp->name);
			printf("X: %d\n", temp->x);
			printf("Y: %d\n", temp->y);
			printf("START: %d\n", temp->start);
			printf("END:   %d\n\n", temp->end);
			temp = temp->next;
		}
	}
	else
		printf("No list\n");
}

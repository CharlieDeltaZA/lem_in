/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_ops_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:15:28 by jhansen           #+#    #+#             */
/*   Updated: 2019/09/17 15:44:33 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static t_links		*create_node(char *line)
{
	t_links	*node;

	node = (t_links *)malloc(sizeof(t_links));
	if (node)
	{
		node->room = ft_strdup(line);
		node->next = NULL;
	}
	return (node);
}

static void			add_node(t_links **head, t_links *node)
{
	t_links	*temp;

	if (*head && node)
	{
		temp = *head;
		if (temp)
		{
			while (temp->next != NULL)
			{
				ft_putstr("Looping until tail\n");		//
				temp = temp->next;
			}
			ft_putstr("Before adding node\n");			//
			temp->next = node;
			ft_putstr("Added node to tail\n");			//
		}
	}
}

void			match_room(t_rooms **head, char *room, char *link)
{
	t_rooms	*temp;
	t_links	*node;

	if (*head && room && link)
	{
		temp = *head;
		while (temp != NULL)
		{
			if (ft_strequ(temp->name, room))
			{
				write(1, "FOUND ROOM\n", 11);		//
				if (temp->links)
				{
					ft_putstr("Create new node and add\n");		//
					node = create_node(link);
					add_node(&temp->links, node);
				}
				else
				{
					ft_putstr("Created first node\n");		//
					temp->links = create_node(link);
				}
			}
			temp = temp->next;
		}
	}
}

void			init_links(t_content **file, t_rooms **head)
{
	t_content	*temp;
	char		**arr;

	temp = *file;
	if (*file && *head)
	{
		while (temp != NULL)
		{
			if ((word_count(temp->content) == 1) && is_link(temp->content))
			{
				arr = ft_strsplit(temp->content, '-');
				write(1, "FOUND LINK\n", 11);				//
				match_room(head, arr[0], arr[1]);	
				free(arr[0]);
				free(arr[1]);
				free(arr);
			}
			temp = temp->next;
		}
	}
}

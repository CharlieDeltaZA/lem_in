/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_ops_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:15:28 by jhansen           #+#    #+#             */
/*   Updated: 2019/09/17 14:59:47 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static t_links		*create_node(char *line)
{
	t_links	*node;

	node = (t_links *)malloc(sizeof(t_links));
	if (node)
	{
		node->room = ft_strdup(line);	//leaking here
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
			write(1, "here\n", 5);			//
			while (temp->next != NULL)
			{
				write(1, "loop\n", 5);		//
				temp = temp->next;
			}
			write(1, "here1\n", 6);			//
			temp->next = node;
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
				if (temp->links)
				{
					write(1, "1\n", 2);
					node = create_node(link);
					add_node(&temp->links, node);
				}
				else
				{
					write(1, "2\n", 2);
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
				match_room(head, arr[0], arr[1]);	
				free(arr[0]);
				free(arr[1]);
				free(arr);
			}
			temp = temp->next;
		}
	}
}

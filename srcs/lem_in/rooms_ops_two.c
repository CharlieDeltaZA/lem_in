/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_ops_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:15:28 by jhansen           #+#    #+#             */
/*   Updated: 2019/09/12 14:55:24 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

static t_links		*create_node(char *line)
{
	t_links	*node;

	node = (t_links *)malloc(sizeof(t_links));
	if (node)
	{
		node->room = ft_strdup(line);		//leaking here????
		node->next = NULL;
	}
	ft_putendl_col_fd(GREEN, "CREATED", 1);
	return (node);
}

static void			add_node(t_links **head, t_links *node)
{
	t_links	*temp;

	if (!(head) || (!(node)))
		return ;
	temp = *head;
	if (temp)
	{
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
	ft_putendl_col_fd(YELLOW, "ADDED", 1);
}

void			match_room(t_rooms **head, char *room, char *link)
{
	t_rooms	*temp;
	t_links	*node;

	temp = *head;
	while (temp != NULL)
	{
		if (ft_strequ(temp->name, room))
		{
			ft_putendl_col_fd(RED, "LINK FOUND", 1);
			if (temp->links)
			{
				node = create_node(link);
				add_node(&(temp->links), node);
			}
			else
				temp->links = create_node(link);
		}
		temp = temp->next;
	}
}

void			init_links(t_content **file, t_rooms **head)
{
	t_content	*temp;
	char		**arr;

	temp = *file;
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

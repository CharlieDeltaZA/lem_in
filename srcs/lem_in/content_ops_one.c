/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_ops_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 12:21:07 by cdiogo            #+#    #+#             */
/*   Updated: 2020/01/14 11:57:15 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

/*
** Creates content node with the line passed to it
*/

static t_content	*create_node(char *line)
{
	t_content	*node;

	node = (t_content *)malloc(sizeof(t_content));
	if (node)
	{
		node->content = ft_strdup(line);
		node->next = NULL;
	}
	return (node);
}

/*
** Adds node to the bottom of the content struct
*/

static void			add_tail(t_content **head, t_content *node)
{
	t_content	*tmp;

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

/*
** Manages the creation of content struct
*/

t_content			*init_content(t_content **file, char *line)
{
	t_content	*node;
	t_content	*head;

	head = *file;
	if (head)
	{
		node = create_node(line);
		add_tail(&head, node);
	}
	else
		head = create_node(line);
	return (head);
}

/*
** Prints the cleaned up and proper version (content struct) of the passed file
*/

void				print_content(t_content **head)
{
	t_content	*node;

	node = *head;
	if (node)
	{
		while (node)
		{
			ft_putendl(node->content);
			node = node->next;
		}
	}
	ft_putchar('\n');
}

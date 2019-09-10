/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_check_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:45:52 by jhansen           #+#    #+#             */
/*   Updated: 2019/09/10 17:56:26 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		check_for_ant(t_content **head)
{
	t_content	*temp;
	t_content	*node;
	int			num;

	temp = *head;
	node = *head;
	if (*head)
	{
		if (is_ant(temp->content))
		{
			num = ft_atol(temp->content);
			if (num > MAX || num < MIN)
				return (0);
			while (node->next != NULL)
			{
				node = node->next;
				if (word_count(node->content) == 1 && is_ant(node->content))
					return (0);
			}
			return (1);
		}
	}
	return (0);
}

t_rooms		*filler(t_content **file, t_rooms **head)
{
	t_content	*temp;

	temp = *file;
	while (temp != NULL)
	{
		if (word_count(temp->content) == 3)
			*head = init_rooms(head, temp->content, 0);
		else if (ft_strequ("##start", temp->content))
		{
			temp = temp->next;
			if (word_count(temp->content) == 3)
				*head = init_rooms(head, temp->content, 1);
		}
		else if (ft_strequ("##end", temp->content))
		{
			temp = temp->next;
			if (word_count(temp->content) == 3)
				*head = init_rooms(head, temp->content, 2);
		}
		temp = temp->next;
	}
	return (*head);
}

int		advanced_check_and_fill(t_content **file, t_rooms **head)
{
	t_content	*temp;

	temp = *file;
	if (!(*file))
		return (0);
	if (check_for_ant(file))
	{
		*head = filler(file, head);
		if (duplicate_rooms(head) && is_endstart(head) && duplicate_link(file))
		{
			// if (existing_room(file))
			// {
			// 	*head = init_links(file, head);
			// 	return (1);
			// }
			return(1);		//only needed without if statement
		}
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:45:52 by jhansen           #+#    #+#             */
/*   Updated: 2019/09/03 17:21:02 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		duplicate_check(t_rooms **rooms)
{
	t_rooms	*temp;
	t_rooms	*current;

	temp = *rooms;
	while (temp->next != NULL)
	{
		current = temp;
		while (current->next != NULL)
		{
			if (compare_rooms(temp, current))		//compare with what??
				return (0);
			current = current->next;
		}
		temp = temp->next;
	}
	return (1);
}

int		check_for_ant(t_content **head)
{
	t_content	*temp;
	int			num;

	if (*head)
	{
		temp = *head;
		if (is_ant(temp->content))
		{
			num= ft_atol(temp->content);
			if (num > MAX || num < MIN)
				return (0);
			return (1);
		}
	}
	return (0);
}

int		advanced_check_and_fill(t_content **file, t_rooms **head)
{
	if (!(*file))
		return (0);
	if (check_for_ant(file))
	{
		head = init_rooms(file, head);
		if (duplicate_check(head) /* && */ )		//links to a valid room(something that exists) AND check that the links of the rooms link up correctly. HOW?
			return (1);
	}
	return (0);
}
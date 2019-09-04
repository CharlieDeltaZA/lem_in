/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:45:52 by jhansen           #+#    #+#             */
/*   Updated: 2019/09/04 18:56:01 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

/*int		duplicate_check(t_rooms **rooms)
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
}*/

int		check_for_ant(t_content **head)
{
	t_content	*temp;
	int			num;

	if (*head)
	{
		temp = *head;
		if (is_ant(temp->content))
		{
			num = ft_atol(temp->content);
			if (num > MAX || num < MIN)
				return (0);
			return (1);
		}
	}
	return (0);
}

t_rooms		*filler(t_content **file, t_rooms **head)
{
	t_content	*temp;
	int			count = 0;		//debug

	temp = *file;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (ft_strequ("##start", temp->content))
		{
			temp = temp->next;							//have to actually check that theres a room after the ##start and ##end still
			*head = init_rooms(head, temp->content, 1);
		}
		else if (ft_strequ("##end", temp->content))
		{
			temp = temp->next;
			ft_putendl(temp->content);
			*head = init_rooms(head, temp->content, 2);
		}
		else if (word_count(temp->content) == 3)
			*head = init_rooms(head, temp->content, 0);
		count++;									//debug
		ft_putnbr_col_fd(GREEN, count, 1);		//debug
		ft_putchar('\n');					//debug
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
		//if (duplicate_check(head) /* && */ )		//links to a valid room(something that exists) AND check that the links of the rooms link up correctly. HOW?
			return (1);
	}
	return (0);
}
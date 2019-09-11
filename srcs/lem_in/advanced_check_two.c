/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_check_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:09:04 by jhansen           #+#    #+#             */
/*   Updated: 2019/09/10 17:55:58 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int			duplicate_rooms(t_rooms **rooms)
{
	t_rooms	*temp;
	t_rooms	*current;

	temp = *rooms;
	while (temp->next != NULL)
	{
		current = temp->next;
		while (current != NULL)
		{
			if ((ft_strequ(temp->name, current->name)
				|| (temp->x == current->x && temp->y == current->y)))
				return (0);
			current = current->next;
		}
		temp = temp->next;
	}
	return (1);
}

int			is_endstart(t_rooms **head)
{
	t_rooms	*temp;
	int		flag;

	temp = *head;
	flag = 0;
	while (temp != NULL)
	{
		if (temp->start == 1)
			flag = 1;
		else if (temp->end == 1)
			flag += 1;		
		temp = temp->next;
	}
	if (flag == 2)
		return (1);
	return (0);
}

int			double_check(char *current, char *temp)
{
	char	**one;
	char	**two;

	one = ft_strsplit(current, '-');
	two = ft_strsplit(temp, '-');
	if (((ft_strequ(one[0], two[0]) && ft_strequ(one[1], two[1]))
		|| (ft_strequ(one[0], two[1]) && ft_strequ(one[1], two[0]))))
	{
		ft_free_array(one);
		ft_free_array(two);
		return (0);
	}
	return (1);
}

int			duplicate_link(t_content **file)
{
	t_content	*temp;
	t_content	*current;

	temp = *file;
	while (temp != NULL)
	{
		if ((word_count(temp->content) == 1) && is_link(temp->content))
		{
			if (temp->next != NULL)
				current = temp->next;
			while (current != NULL)
			{
				if ((word_count(current->content) == 1) && is_link(current->content))
				{
					if (double_check(temp->content, current->content) == 0)
						return (0);
				}
				current = current->next;
			}
		}
		temp = temp->next;
	}
	return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_out_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:08:43 by jhansen           #+#    #+#             */
/*   Updated: 2019/09/17 12:09:18 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	free_rooms_error(t_rooms **node, int msg)
{
	free_rooms(node);
	error_out(msg);
	exit(1);
}

void				free_rooms(t_rooms **head)
{
	t_rooms	*temp;
	t_rooms	*next;
	t_links	*temp_l;
	t_links	*next_l;

	if (*head != NULL)
	{
		temp = *head;
		while (temp)
		{
			next = temp->next;
			if (temp->links != NULL)
			{
				temp_l = temp->links;
				while (temp_l)
				{
					next_l = temp_l->next;
					free(temp_l->room);
					free(temp_l);
					temp_l = next_l;
				}
				temp_l = NULL;
			}
			free(temp->name);
			free(temp);
			temp = next;
		}
		*head = NULL;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_out_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <jhansen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:08:43 by jhansen           #+#    #+#             */
/*   Updated: 2019/09/17 12:18:42 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	free_rooms_error(t_rooms **node, int msg)
{
	free_rooms(node);
	error_out(msg);
	exit(1);
}

void                free_links(t_links **links)
{
	t_links	*temp;
	t_links	*next;

	if (*links != NULL)
	{
		temp = *links;
		while (temp)
		{
			next = temp->next;
			free(temp->room);
			free(temp);
            temp = next;
		}
		*links = NULL;
	}
}

void				free_rooms(t_rooms **head)
{
	t_rooms	*temp;
	t_rooms	*next;

	if (*head != NULL)
	{
		temp = *head;
		while (temp)
		{
			next = temp->next;
            free_links(&temp->links);
			free(temp->name);
			free(temp);
			temp = next;
		}
		*head = NULL;
	}
}
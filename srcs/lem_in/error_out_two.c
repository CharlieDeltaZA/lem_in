/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_out_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <cdiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 12:08:43 by jhansen           #+#    #+#             */
/*   Updated: 2020/01/07 13:28:12 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void	free_rooms_error(t_rooms **node, int msg)
{
	free_rooms(node);
	error_out(msg);
	exit(1);
}

void	free_links(t_links **links)
{
	t_links	*temp;
	t_links	*next;

	next = NULL;
	temp = *links;
	if (temp)
	{
		while (temp != NULL)
		{
			next = temp->next;
			free(temp->name);
			free(temp);
			temp = next;
		}
		*links = NULL;
	}
}

void	free_rooms(t_rooms **head)
{
	t_rooms	*temp;
	t_rooms	*next;

	next = NULL;
	if (*head != NULL)
	{
		temp = *head;
		while (temp)
		{
			next = temp->next;
			if (temp->links)
				free_links(&temp->links);
			free(temp->name);
			free(temp);
			temp = next;
		}
		*head = NULL;
	}
}

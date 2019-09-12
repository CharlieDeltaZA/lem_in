/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_ops_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:15:28 by jhansen           #+#    #+#             */
/*   Updated: 2019/09/12 13:16:00 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void		init_links(t_content **file, t_rooms **head)
{
	t_content	*temp;
	t_rooms		*room;

	temp = *file;
	room = *head;
	while (temp != NULL)
	{
		if ((word_count(temp->content) == 1) && is_link(temp->content))
		{

			//get the two room links from the link
			//find a match of the two link names to the room/s
			//add a link struct node into the respectiveroom struct
		}
		temp = temp->next;
	}
}

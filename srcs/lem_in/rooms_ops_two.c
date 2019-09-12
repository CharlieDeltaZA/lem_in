/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms_ops_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:15:28 by jhansen           #+#    #+#             */
/*   Updated: 2019/09/12 14:16:53 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

void		match_room(t_rooms **head, char *room, char *link)
{
	t_rooms	*temp;
	t_links	*node;

	temp = *head;
	while (temp != NULL)
	{
		if (ft_strequ(temp->name, room))
		{
			if (temp->links)
			{
				node = create_node(link);
				add_node(temp->links, node);
			}
			else
				temp->links = create_node(link);
		}
		temp = temp->next;
	}
}

void		init_links(t_content **file, t_rooms **head)
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
			ft_free_array(arr);			//test if this free works here
		}
		temp = temp->next;
	}
}

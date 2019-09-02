/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:45:52 by jhansen           #+#    #+#             */
/*   Updated: 2019/09/02 13:31:40 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		check_for_ant(t_content **head)
{
	t_content	*temp;

	if (*head)
	{
		temp = *head;
		while (temp->next != NULL)
		{
			if (is_ant(temp->content))
				return (1);
			temp = temp->next;
		}
	}
	return (0);
}

int		advanced_check_and_fill(t_content **file, t_rooms **head)
{
	if (check_for_ant(file))
	{
		//check that the co-ordinates of the rooms are valid are valid. HOW?
		//check that the links of the rooms link up correctly. HOW?
	}
	else
		return (0);
}
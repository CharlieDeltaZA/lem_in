/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:15:37 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/26 16:39:22 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		check_line(char *line)
{
	if (is_command(line) == 1)
		return (1);
	else if (is_commment(line) == 1)
		return (3);						//value '3' is used so its not added to list and not considered and error
	else if (is_link(line) == 1)
		return (1);
	else if (is_ants(line) == 1)
		return (1);
	else if (is_room(line) == 1)
		return (1);
	else
		return (0);
}

void	read_map(void)
{
	char		*line;
	t_content	*file;
	t_rooms		*head;

	head = NULL;
	file = NULL;
	while (get_next_line(0, &line))
	{
		if (check_line(line) == 1)
			init_content(&file, line);
		else if (check_line(line) == 0)
			free_and_error(file, head, BAD_INPUT);
		free(line);
	}
	//function to fill t_rooms here using 'file' node
	print_content(&file);
	free_content(&file);
}

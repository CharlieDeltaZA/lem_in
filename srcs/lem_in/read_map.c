/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:15:37 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/26 15:47:59 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		check_line(char *line)
{
	if (is_command(line) == 1)
		return (1);
	else if (is_commment(line) == 1)
		return (2);
	else if (is_link(line) == 1)
		return (3);
	else if (is_ants(line) == 1)
		return (4);
	else if (is_room(line) == 1)
		return (5);
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
		if (check_line(line) > 0)
			init_content(&file, line);
		else
			free_and_error(file, head, BAD_INPUT);
		free(line);
	}
	//function to fill t_rooms here using 'file' node
	print_content(&file);
	free_content(&file);
}

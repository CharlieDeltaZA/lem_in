/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:15:37 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/26 15:02:34 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		type_of_line(char *line)
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

int		check_line(char *line)
{
	int	flag;

	if (!line[0])
		error_out(EMPTY_LINE);
	flag = type_of_line(line);
	if (flag == 1)
		return (valid_command(line));
	if (flag == 2)
		return (1);
	if (flag == 3)
		return (valid_link(line));
	if (flag == 4)
		return (valid_ants(line));
	if (flag == 5)
		return (valid_room(line));
	else
		return (-42);
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

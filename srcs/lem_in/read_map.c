/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:15:37 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/27 13:05:31 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		check_line(char *line)
{
	int		i;
	char	*temp;

	temp = line;
	i = 0;
	while (temp[i] != '\0' && temp[i] == '\t' && temp[i] == ' ')	//checking if line is empty
		i++;
	if (temp[i] != '\0')
	{
		if (is_command(line) == 1)
			return (1);
		else if (is_command(line) == 3)
			return (3);						//value '3' is used so its not added to list and not considered and error
		else if (is_comment(line) == 1)
			return (3);						//value '3' is used so its not added to list and not considered and error
		else if (is_ant(line) == 1)
			return (1);
		else if (is_room(line) == 1)
			return (1);
		else if (is_link(line) == 1)
			return (1);
		else
			return (0);
	}
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
		else
			free_and_error(file, head, BAD_INPUT);
		free(line);
	}
	//advanced_check_and_fill(&file);				//function to fill t_rooms here using 'file' node
	print_content(&file);
	free_content(&file);
}

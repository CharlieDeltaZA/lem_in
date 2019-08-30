/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:15:37 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/30 12:14:51 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int			word_manager(char *line, int words)
{
	if (words == 1)
	{
		if (is_command(line) == 1)
			return (1);
		else if (is_ant(line))
			return (1);
		else if (is_link(line))
			return (1);
	}
	else if (words == 3)
	{
		if (is_room(line))
			return (1);
	}
	return (0);
}

void		check_line(char *line, t_content **file, t_rooms **rooms)
{
	int	words;
	int	status;

	if (is_comment(line))
		return ;
	words = word_count(line);
	status = word_manager(line, words);
	if (status == 0)
		free_and_error(file, rooms, BAD_INPUT);
	init_content(file, line);
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
		check_line(line, &file, &head);
		free(line);
	}
	//advanced_check_and_fill(&file);			//function to fill t_rooms here using 'file' node
	print_content(&file);
	free_content(&file);
}

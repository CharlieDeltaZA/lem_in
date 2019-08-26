/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:15:37 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/26 12:12:34 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		check_line(char *line)
{
	int			num_ants;

	if (!line[0])
		error_out(EMPTY_LINE);
	if (line)
	{
		num_ants = check_ants(line);
		if (num_ants <= 0)
			error_out(NO_ANTS);
		printf("Num Ants: %d\n", num_ants);
	}
	if (is_command(line))
	{
		printf("Found Command: %s\n", line);
	}																//NEEDS WORK
	if (is_comment(line))
	{
		printf("Found Comment: %s\n", line);
	}
	if (is_room(line))
	{
		//validate room
		printf("Found Room\n");
	}
	if (is_link(line))
	{
		//validate link?
		printf("Found Link\n");
	}
	printf("%s\n", line);
	return (0);
}

void	read_map(void)
{
	char		*line;
	t_content	*file;

	file = NULL;
	while (get_next_line(0, &line))
	{
		check_line(line);
		init_content(&file, line);
		free(line);
	}
	//function to fill t_rooms here using 'file' node
	print_content(&file);
	free_content(&file);
}

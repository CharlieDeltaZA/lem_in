/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:15:37 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/22 11:43:58 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	read_map(void)
{
	//TODO
	char	*line;
	int		count;
	// int		check;
	// int		num_ants;
	
	count = 1;
	while (get_next_line(0, &line))
	{
		read_line(line, count);
		count++;
	}
}

int		read_line(char *line, int check)
{
	//TODO
	int			num_ants;

	if (check == 1 && line)
	{
		num_ants = check_ants(line);
		if (num_ants <= 0)
			error_out(NO_ANTS);
		printf("Num Ants: %d\n", num_ants);
	}
	if (is_command(line))
	{
		printf("Found Command: %s\n", line);
	}
	if (is_comment(line))
	{
		printf("Found Comment: %s\n", line);
	}
	// if (is_room(line))
	// {
	// 	printf("Found Room\n");
	// }
	// if (is_link(line))
	// {
	// 	printf("Found Link\n");
	// }
	printf("Line: %d \t %s\n", check, line);
	return (0);
}

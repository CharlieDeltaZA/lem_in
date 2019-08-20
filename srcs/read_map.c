/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:15:37 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/20 12:04:24 by cdiogo           ###   ########.fr       */
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
		// if (check && line)
		// 	if (ft_str_is_numeric(line))
		// 	{
		// 		check = 0;
		// 		num_ants = ft_atoi(line);
		// 		// ft_putendl
		// 	}
		// 	else
		// 		err_out(rip);
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
			error_out(ANTS);
		printf("Num Ants: %d\n", num_ants);
	}
	printf("Line: %d \t %s\n", check, line);
	return (0);
}

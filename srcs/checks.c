/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:17:39 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/22 12:05:37 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

// THESE CHECKS ARE VERY BASIC AND SHOULD BE UPDATED TO BE MORE ROBUST!

int		check_ants(char *line)
{
	if (ft_str_is_numeric(line))
	{
		if (ft_atoi(line) <= 0)
			return (-1);
		else
			return (ft_atoi(line));
	}
	return (-42);
}

int		is_command(char *line)
{
	char	*tmp;

	tmp = line;
	if (line[0] == '#' && line[1] == '#')
	{
		tmp += 2;
		if (ft_strequ("start", tmp))
		{
			printf("Found Start\n");
			return (1);
		}
		else if (ft_strequ("end", tmp))
		{
			printf("Found End\n");
			return (1);
		}
		else
			error_out(BAD_COMMAND);
	}
	return (0);
}

int		is_comment(char *line)
{
	if (line[0] == '#' && line[1] != '#')
	{
		return (1);
	}
	return (0);
}

int		is_room(char *line)
{
	if (count_words(line, ' ', 0) == 3 && line[0] != '#')
		return (1);
	return (0);
}

int		is_link(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

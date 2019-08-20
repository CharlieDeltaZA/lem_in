/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:17:39 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/20 16:22:00 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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
			return (0);	
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

}

int		is_link(char *line)
{
	
}

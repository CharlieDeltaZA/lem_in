/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_errors_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:17:39 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/27 17:32:08 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		is_command(char *line)
{
	char	*tmp;

	tmp = line;
	if (line[0] == '#' && line[1] == '#')
	{
		tmp += 2;
		if (ft_strequ("start", tmp))     //strequ wont work with spaces or tabs at the end
		{
			write(1, "command\n", 8);
			return (1);
		}
		else if (ft_strequ("end", tmp))
		{
			write(1, "command\n", 8);
			return (1);
		}
		else
		{
			write(1, "shit command\n", 13);
			return (3);
		}
	}
	return (0);
}

int		is_comment(char *line)
{
	if (line[0] == '#' && line[1] != '#')
	{
		write(1, "comment\n", 8);
		return (1);
	}
	return (0);
}

int		is_link(char *line)
{
	int	i;

	i = 0;
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	if (num_or_lett(&line[i], '-') == 1 && line[i] != 'L')
	{
		while (line[i] != '-' && line[i] != '\0')
			i++;
		i++;
		if (line[i] && line[i] != 'L')
		{
			if (num_or_lett(&line[i], '\0') == 1)
			{
				write(1, "is_link\n", 8);	
				return (1);
			}
		}
		else
			return (0);
	}
	return (0);
}

int		is_ant(char *line)
{
	int	i;

	i = 0;
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	while (line[i] != '\0' && line[i] >= '0' && line[i] <= '9')
		i++;
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	if (line[i] == '\0')
	{
		write(1, "is_ant\n", 7);
		return (1);
	}
	return (0);
}

int		is_room(char *line)
{
	int	i;

	i = 0;
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	if (count_rooms(&line[i]) == 3 && line[i] != 'L' && line[i] != '#')
	{
		while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')  				//Doesn't work with spaces or tabs at the end
			i++;
		while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
			i++;
		if (digit_room_check(&line[i]) == 1)
		{
			write(1, "is_room\n", 8);
			return (1);
		}
	}
	return (0);
}
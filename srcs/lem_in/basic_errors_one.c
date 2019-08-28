/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_errors_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:17:39 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/28 15:43:49 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		is_command(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0' && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '#' && line[i + 1] == '#')
	{
		i = i + 2;
		if (ft_strequ("start", line) || ft_strequ("end", line))     //strequ wont work with spaces or tabs at the end
		{
			write(1, "command\n", 8);		//
			return (1);
		}
		else
		{
			write(1, "shit command\n", 13);		//
			return (3);
		}
	}
	return (0);
}

int		is_comment(char *line)
{
	int	i;

	i = 0;
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	if (line[i] == '#' && line[i + 1] != '#')
	{
		write(1, "comment\n", 8);		//
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
	if (dash_check(&line[i]) && line[i] != 'L')
	{
		write(1, "is_link\n", 8);		//
		return (1);
	}
	return (0);
}

int		is_ant(char *line)
{
	int	i;

	i = 0;
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	while (line[i] != '\0')
	{
		if (line[i] >= '0' && line[i] <= '9')
			i++;
		else
			return (0);
	}
	write(1, "is_ant\n", 7);		//
	return (1);
}

int		is_room(char *line)
{
	int	i;

	i = 0;
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	if (line[i] != 'L')
	{
		while (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')  				//Doesn't work with spaces or tabs at the end
			i++;
		while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
			i++;
		if (all_digits_check(&line[i]))
		{
			write(1, "is_room\n", 8);
			return (1);
		}
	}
	return (0);
}
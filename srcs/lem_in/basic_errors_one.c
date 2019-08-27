/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_errors_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:17:39 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/27 12:58:46 by jhansen          ###   ########.fr       */
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
		if (ft_strequ("start", tmp))
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
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')  //goes over first white space
		i++;
	if (num_or_lett(&line[i], '-') == 1)					//checks that the characters before the '-' are all numbers or letters
	{
		while (line[i] != '-' && line[i] != '\0')		//goes over all characters until '-'
			i++;
		if (line[i])								//if the line isnt done (if it is then error)
		{
			if (num_or_lett(&line[i], '\0') == 1)		//then checks if the characters after the '-' are letters or numbers or spaces(check for '\0' means it will also skip over white space)
			{
				write(1, "is_link\n", 8);	
				return (1);							//if it is then success
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
	int	count;

	i = 0;
	count = 3;
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')  //goes over first white space
		i++;
	if (count_words(&line[i]) == 3 && line[i] != 'L' && line[i] != '#')  //checks if the word count is 3
	{
		while (count--)
		{
			if (num_or_lett(&line[i], ' ') == 1)			//checks if all the characters up to a ' ' or a tab(skips over this if checking for ' ') is numbers or letters
			{
				while ((line[i] != ' ' || line[i] != '\t') && line[i] != '\0')  //goes over the characters that have been checked and over the next white spaces
					i++;
				while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
					i++;
			}
			else
				return (0);
		}
		write(1, "is_room\n", 8);
		return (1);
	}
	return (0);
}
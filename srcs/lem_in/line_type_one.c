/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_type_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:17:39 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/26 16:39:17 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		is_command(char *line)
{
	// char	*tmp;

	// tmp = line;
	if (line[0] == '#' && line[1] == '#')
	{
		// tmp += 2;
		// if (ft_strequ("start", tmp))
		// 	return (1);
		// else if (ft_strequ("end", tmp))
			return (1);
	}
	return (0);
}

int		is_comment(char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (1);
	return (0);
}

int		is_link(char *line)
{
	int	i;

	i = 0;
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	while (line[i])
	{
		if (line[i] == '-')
		{
			if (is_lower(line[i + 1]) || is_upper(line[i + 1]) || is_num(line[i + 1]))   //FUNCTIONS THAT EXIST FOR THESE??
			{
				if (is_lower(line[i - 1]) || is_upper(line[i - 1]) || is_num(line[i - 1]))
					return (1);
			}
		}
		i++;
	}
	return (0);
}

int		is_ant(char *line)
{
	int	i;

	i = 0;
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')		//NOT DONE
		i++;
	
}

int		is_room(char *line)
{
	int	i;

	i = 0;
	while ((line[i] == ' ' || line[i] == '\t') && line[i] != '\0')
		i++;
	if (count_words(&line[i], ' ', 0) == 3 && line[i] != 'L' && line[i] != '#')  //DONE??
		return (1);
	return (0);
}
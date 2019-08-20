/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 10:43:46 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/20 13:27:03 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	error_out(int code)
{
	if (code == ANTS)
		ft_putendl_col_fd(RED, "ERROR : No ants provided", 2);
	exit(1);
}

int		is_command(char *line)
{
	char	*tmp;

	tmp = line;
	if (line[0] == '#' && line[1] == '#')
	{
		tmp += 2;
		// line += 2;
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

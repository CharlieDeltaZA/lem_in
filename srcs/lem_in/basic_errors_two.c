/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_errors_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 08:37:21 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/27 17:44:10 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		word_count(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
			i++;
		if (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
			count++;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
			i++;
	}
	return (count);
}

int		num_or_lett(char *str, char delim)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != delim)
	{
		if (((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= '0' && str[i] <= '9')))
			i++;
		else if ((str[i] == ' ' || str[i] == '\t') && delim == '\0')
		{
			while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				return (1);
			else
				return (0);
		}
		else
			return (0);	
	}
	return (1);
}

int		digit_room_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

int		count_rooms(char const *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!(*str))
		return (0);
	while (str[i] != '\0')
	{
		while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
			i++;
		if (str[i] != '\0')
		{
			while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
				i++;
			count++;
		}
		else if (count < 3)
			return (0);
	}
	return (count);
}

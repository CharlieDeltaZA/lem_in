/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_errors_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 08:37:21 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/27 13:59:54 by jhansen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int		num_or_lett(char *str, char delim)
{
	int	i;
	char extra;

	i = 0;
	extra = '\0';
	if (delim == '\0')
	{
		extra = ' ';
		delim = '\t';
	}
	else if (delim == ' ')
		extra = '\t';
	while (str[i] != extra && str[i] != delim && str[i] != '\0')
	{
		if (((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= '0' && str[i] <= '9')))
			i++;
		else
			return (0);
	}
	return (1);
}

int		count_words(char const *str)
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

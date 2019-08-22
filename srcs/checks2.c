/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 08:37:21 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/22 08:39:24 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		count_words(char const *str, char delim, int index)
{
	int	count;

	if (!(str[index]))
		return (0);
	count = 0;
	while (str[index] == delim)
		index++;
	while (str[index] != '\0' && str[index] != delim)
	{
		index++;
		count = 1;
	}
	return (count + count_words(str, delim, index));
}

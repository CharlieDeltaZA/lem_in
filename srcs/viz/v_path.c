/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_path.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <cdiogo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 16:41:22 by bmarks            #+#    #+#             */
/*   Updated: 2020/01/06 14:20:09 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in2.h"

void	free_paths(t_path **path)
{
	t_path *next;

	if (!*path)
		return ;
	while (*path)
	{
		next = (*path)->next_room;
		free((*path)->room_name);
		free(*path);
		*path = (*path)->next_room;
	}
	*path = NULL;
}

t_path	*new_path(char *room_name)
{
	t_path *new;

	if (!(new = (t_path *)malloc(sizeof(t_path))))
		MAL_ERROR;
	new->room_name = ft_strdup(room_name);
	new->next_room = NULL;
	return (new);
}

t_path	*add_path(t_path **path, char *room_name)
{
	t_path *tmp;

	tmp = *path;
	if (!*path)
	{
		*path = new_path(room_name);
		return (*path);
	}
	while (tmp->next_room)
		tmp = tmp->next_room;
	tmp->next_room = new_path(room_name);
	return (*path);
}

size_t	path_length(t_path *path)
{
	size_t	index;

	index = 0;
	while (path)
	{
		index++;
		path = path->next_room;
	}
	return (index);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_error.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:52:14 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/30 16:22:46 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/viz.h"

void	viz_free(t_viz **viz)
{
	if (viz && *viz)
	{
		SDL_DestroyRenderer((*viz)->rend);
		SDL_DestroyTexture((*viz)->ant);
		SDL_DestroyTexture((*viz)->room);
		SDL_DestroyTexture((*viz)->bg);
		SDL_DestroyWindow((*viz)->window);
		free(*viz);
		(*viz) = NULL;
	}
}

void	viz_error_free(t_viz *viz, const char *error)
{
	if (viz)
		viz_free(&viz);
	ft_putendl_col_fd(RED, (char*)error, 2);
	exit(1);
}

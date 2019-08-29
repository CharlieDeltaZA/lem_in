/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 12:17:02 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/29 12:52:32 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/viz.h"

t_viz			*init_viz(void)
{
	//TODO
}

SDL_Window		*init_window(t_viz *viz)
{
	SDL_Window	*win;

	if (!(win = SDL_CreateWindow("Lem-in Visualizer",
						SDL_WINDOWPOS_CENTERED,
						SDL_WINDOWPOS_CENTERED,
						WIDTH, HEIGHT, 0)))
		viz_error_free(viz, SDL_GetError());
	return (win);
}

SDL_Renderer	*init_renderer(t_viz *viz)
{
	SDL_Renderer	*ren;

	if (!(ren = SDL_CreateRenderer(viz->window, -1, SDL_RENDERER_ACCELERATED)))
		viz_error_free(viz, SDL_GetError());
	return (ren);
}

SDL_Texture		*init_texture(t_viz *viz, char *img_path)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	surface = IMG_Load(img_path);
	texture = SDL_CreateTextureFromSurface(viz->rend, surface);
	SDL_FreeSurface(surface);
	if (!texture)
		viz_error_free(viz, SDL_GetError());
	return (texture);
}

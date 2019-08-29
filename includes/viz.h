/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viz.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 09:51:11 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/29 12:51:56 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIZ_H
# define VIZ_H

# include "lem_in.h"
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_timer.h>
# include <SDL2/SDL2_gfxPrimitives.h>

//Header for visualizer
# define WIDTH 1920
# define HEIGHT 1080

typedef struct 		s_viz
{
	SDL_Window		*window;
	SDL_Renderer	*rend;
	SDL_Texture		*ant;
	SDL_Texture		*room;
	SDL_Texture		*bg;
	int				close;

}					t_viz;

/*
** Init functions for SDL textures/windows/renderer
*/

SDL_Window			*init_window(t_viz *viz);
SDL_Renderer		*init_renderer(t_viz *viz);
SDL_Texture			*init_texture(t_viz *viz, char *img_path);

/*
** Free and Error print function
*/

void				viz_error_free(t_viz *viz, char *error);

#endif

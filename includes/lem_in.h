/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiogo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 08:40:20 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/26 08:47:59 by cdiogo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

// DEBUGGING VVV
# include <stdio.h>
// DEBUGGING ^^^

/*
** Macros
*/

enum					e_error_codes
{
	NO_ANTS = 1,
	DUP_ROOM,
	DUP_LINK,
	NO_START,
	NO_END,
	NO_X,
	NO_Y,
	BAD_INPUT,
	BAD_COMMAND,
	EMPTY_LINE
};

typedef struct			s_content
{
	char				*content;
	struct s_content	*next;
}						t_content;

typedef struct			s_rooms
{
	char				*name;
	int					x;
	int					y;
	int					start;
	int					end;
	// links?
	struct s_rooms		*next;
}						t_rooms;

/*
** Reading of Input
*/

void					read_map(void);
int						read_line(char *line, int check);

/*
**  t_content funcs
*/

t_content				*init_content(t_content **file, char *line);
void					print_content(t_content **head);
void					free_content(t_content **head);

/*
**	t_rooms funcs
*/

t_rooms					*init_rooms(t_rooms **file, char *line);
void					free_rooms(t_rooms **head);

/*
** Error & Validation funcs
*/

void					free_and_error(int msg);
void					error_out(int code);
int						check_ants(char *line);
int						is_command(char *line);
int						is_comment(char *line);
int						is_room(char *line);
int						is_link(char *line);
int						count_words(char const *str, char delim, int index);

#endif

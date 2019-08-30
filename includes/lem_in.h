/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhansen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 08:40:20 by cdiogo            #+#    #+#             */
/*   Updated: 2019/08/30 12:47:53 by jhansen          ###   ########.fr       */
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
	struct s_rooms		*next;
}						t_rooms;

/*
** Reading & Basic Error Checks of Input
*/

void					read_map();
void					check_line(char *line, t_content **file, t_rooms **head);
int						word_manager(char *line, int words);
int						word_count(char *str);
int						is_command(char *line);
int						is_comment(char *line);
int						is_room(char *line);
int						is_link(char *line);
int						is_ant(char *line);
int						all_digits_check(char *str);
int						dash_check(char *str);
void					free_and_error(t_content **file, t_rooms **node, int msg);
void					error_out(int code);

/*
** Further Error Checking
*/

void					advanced_check_and_fill(t_content **file, t_rooms **head);
int						valid_command(char *line);
int						valid_link(char *line);
int						valid_room(char *line);

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

#endif

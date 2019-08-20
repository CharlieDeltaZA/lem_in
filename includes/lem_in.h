#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

// DEBUGGING VVV
# include <stdio.h>
// DEBUGGING ^^^

/*
** Macros
*/

# define ANTS 1

typedef struct		s_rooms
{
	char			*name;
	int				x;
	int				y;
	int				start;
	int				end;
	// links?
	struct s_rooms	*next;
}					t_rooms;

/*
** Reading of Input
*/

void				read_map(void);
int					read_line(char *line, int check);

/*
**  Input Validation
*/

int					check_ants(char *line);

/*
** Error funcs
*/

void				error_out(int code);

#endif

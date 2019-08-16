#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"

typedef struct		s_rooms
{
	char			*name;
	int				x;
	int				y;
	// links?
	struct s_rooms	*next;
}					t_rooms

#endif

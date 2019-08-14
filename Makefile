##############
#			 #
#   Lem-in   #
#			 #
##############

NAME = lem-in
LIB = libft
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC_DIR = ./srcs/
OBJ_DIR = ./srcs/
INC_DIR = ./includes/
OPTIONS = -I$(INC_DIR) -I./libft -lft -L./libft

OBJ = $(OBJ_DIR)lem_in.o

all: $(LIB) $(NAME)

$(LIB): relib cleanlib
	@echo "[$(LIB)] compiled"

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(FLAGS) $(OPTIONS) $(OBJ) 
	@echo "[$(NAME)] compiled"

clean:
	@/bin/rm -f $(OBJ_DIR)*.o
	@echo "Object files removed"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "[$(NAME)] removed"

re: fclean all

relib:
	@$(MAKE) -C ./libft re

cleanlib:
	@$(MAKE) -C ./libft clean

fcleanlib: cleanlib
	@$(MAKE) -C ./libft fclean
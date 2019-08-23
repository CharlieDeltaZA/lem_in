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
HDR = ./includes/lem_in.h

OBJ = $(OBJ_DIR)lem_in.o $(OBJ_DIR)read_map.o $(OBJ_DIR)check_errors_one.o
OBJ += $(OBJ_DIR)check_errors_two.o $(OBJ_DIR)error_output.o $(OBJ_DIR)list_content.o
OBJ += $(OBJ_DIR)list_rooms.o

all: $(LIB) $(NAME)

$(LIB): relib cleanlib
	@echo "[$(LIB)] compiled"

%.o: $(SRC_DIR)%.c $(HDR)
	@$(CC) $(FLAGS) $(OPTIONS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) -o $(NAME) $(FLAGS) $(OPTIONS) $(OBJ)
	@echo "[$(NAME)] compiled"

debug: $(LIB)
	@$(CC) -o $(NAME) $(FLAGS) $(OPTIONS) ./srcs/*.c -g
	@echo "Debug binary compiled"

cdebug:
	@/bin/rm -rf ./lem-in.dSYM
	@echo "Debug cleaned"

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
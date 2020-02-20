# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: seanseau <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/09/09 13:43:35 by seanseau     #+#   ##    ##    #+#        #
#    Updated: 2019/09/09 13:43:55 by seanseau    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fdf
CC = gcc
FLAGS = -Wall -Wextra -Werror
INC = ./includes/fdf.h\

FILES = parser.c\
		projection.c\
		main.c\
		key_press.c\
		modifier.c\
		utils.c\

SRC = $(addprefix ./src/, $(FILES))
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o : %.c
		$(CC) $(FLAGS) -o $@ -c $< -I $(INC)

$(NAME): $(OBJ)
		make -C libft
		$(CC) $(FLAGS) $(SRC) libft/libft.a ./includes/minilibx_macos/libmlx.a -framework OpenGL -framework Appkit -o $(NAME)

clean:
		make -C libft clean
			rm -f $(OBJ)

fclean: clean
		make -C libft fclean
			rm -f $(NAME)

re: fclean all

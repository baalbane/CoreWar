# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/17 16:41:46 by ttridon           #+#    #+#              #
#    Updated: 2017/03/01 16:48:01 by ttridon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = vm

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -I includes -I ../ressources/libft/includes

LDFLAGS = -L ../ressources/libft -lncurses

LDLIBS = -lft

SRC_NAME = 	vm.c		parsing.c	arena.c		game_loop.c functions/live.c \
			tools.c		functions/ld.c		functions/st.c		functions/add.c \
			functions/sub.c		functions/and.c		functions/or.c	\
			functions/xor.c		functions/zjmp.c	functions/ldi.c	\
			functions/sti.c		functions/fork.c

SRC_PATH = src/

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = obj/

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mkdir $(OBJ_PATH)/functions 2> /dev/null || true
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -f $(SRC:.c=.o)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

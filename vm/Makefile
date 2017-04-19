# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/17 16:41:46 by ttridon           #+#    #+#              #
#    Updated: 2017/04/19 16:05:47 by ttridon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

CC = gcc

CFLAGS = -Wall -Wextra

CPPFLAGS = -I includes -I ../ressources/libft/includes

LDFLAGS = -L ../ressources/libft -lncurses

LDLIBS = -lft

SRC_NAME = 	vm.c	parsing.c	champions.c		arena.c		process.c	\
			game_loop.c													\
			functions/live.c	functions/ld.c	functions/st.c			\
			functions/add.c		functions/sub.c	functions/and.c			\
			functions/or.c		functions/xor.c	functions/zjmp.c		\
			functions/ldi.c		functions/sti.c	functions/fork.c		\
			functions/lld.c		functions/lldi.c						\
			functions/lfork.c	functions/aff.c	functions/tools.c		\
			champion_bis.c		process_bis.c	functions/tools_bis.c

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

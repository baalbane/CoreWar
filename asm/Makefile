# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/17 16:41:46 by ttridon           #+#    #+#              #
#    Updated: 2016/11/18 13:47:38 by ttridon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CPPFLAGS = -I includes -I ../ressources/libft/includes

LDFLAGS = -L ../ressources/libft

LDLIBS = -lft

SRC_NAME = asm.c	if_valid_part1.c	error.c

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
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -f $(SRC:.c=.o)
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

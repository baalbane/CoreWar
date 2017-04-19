# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/19 15:12:13 by ttridon           #+#    #+#              #
#    Updated: 2017/04/19 16:01:06 by ttridon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM = asm

COREWAR = corewar

LIBFT = ressources/libft

.PHONY: all, libft, clean, fclean, re

all: libft
	make -C asm
	make -C corewar

libft:
	make -C $(LIBFT)

clean:
	make -C $(ASM) clean
	make -C $(COREWAR) clean
	make -C $(LIBFT) clean

fclean:
	make -C $(ASM) fclean
	make -C $(COREWAR) fclean
	make -C $(LIBFT) fclean

re: fclean all

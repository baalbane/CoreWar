NAME = asm

SRC_PATH = src/
SRC_NAME =	asm.c	tool.c \
			read.c	gnl.c \
			if_valid_part2.c \
			check.c set_pos.c \
			check2.c write.c  write2.c \
			get_op_tab/get_op_tab.c get_op_tab/get_op_tab2.c \
			get_op_tab/get_op_tab3.c get_op_tab/get_op_tab4.c \
			tool2.c check3.c free_all.c

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Include/
RM = rm -f


all: $(NAME)

$(NAME):
		@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@$(RM) /includes/asm.h.gch

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:04:56 by ttridon           #+#    #+#             */
/*   Updated: 2016/11/26 13:33:25 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

#include "libft.h"
#include "define.h"

#include <stdio.h>

typedef char			t_arg_type;

typedef struct			s_function		//list de fonctions.
{
	char				*line;			//operation + arguments.
	struct s_function	*next;
}						t_function;


typedef struct			s_label			//list de label.
{
	char				*line;			//nom du label.
	struct s_function	*function;		//debut de la list function du label.
	struct s_label		*start;			//debut de la list label.
	struct s_label		*next;
}						t_label;

typedef struct			s_op
{
	char				*name;
	char				args_number;
	char				args_type[4];
	char				op_code;
	int					cycle_number;
	char				*description;
	char				octet_codage;
	char				carry;
}						t_op;


typedef struct			s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}						t_header;

void					get_op_tab();
int						check_name_comment(int fd);
int						error_name_comment(int error_type, char *line, char *tmp);
int						parser(char *file);

#endif

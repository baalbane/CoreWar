/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:04:56 by ttridon           #+#    #+#             */
/*   Updated: 2016/11/26 15:09:23 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

#include "libft.h"
#include "define.h"

#include <stdio.h>

typedef char		t_arg_type;


typedef struct		s_function
{
	char				*line;
	struct s_function	*next;
}					t_function;


typedef struct		s_label
{
	char				*name;
	struct s_function	*function;
	struct s_label		*next;
}					t_label;


typedef struct		s_op
{
	char			*name;
	char			args_number;
	char			args_type[4];
	char			op_code;
	int				cycle_number;
	char			*description;
	char			octet_codage;
	char			carry;
}					t_op;


typedef struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

void				get_op_tab();
int					check_name_comment(int fd);
int					error_name_comment(int error_type, char *line, char *tmp);
int					parser(char *file);

t_label				*tmpname(int fd);
t_label				*new_label(t_label *label, char *line);
int					new_function(t_label *label, char *line);
t_function			*new_lst_function(char *line);
int					is_label(char *line);

char				*tmp_name(t_label *new, char *line);
int					tmp_name_check_function(t_label *new, char *line);
int					tmp_name_strchr(char *line, char a);
int					del_commentaire(char *line);


//DEGUG
int					print_struct(t_label *start);

#endif

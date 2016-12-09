/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:04:56 by ttridon           #+#    #+#             */
/*   Updated: 2016/12/09 17:53:07 by baalbane         ###   ########.fr       */
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
	int				args_number;
	int				args_type[4];
	char			op_code;
	int				cycle_number;
	char			*description;
	int				octet_codage;
	int				carry;
	struct s_op		*next;
}					t_op;


typedef struct		s_header
{
	unsigned int	magic;
	char			prog_name[PROG_NAME_LENGTH + 1];
	unsigned int	prog_size;
	char			comment[COMMENT_LENGTH + 1];
}					t_header;

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

int					check_all_label(t_label *label, t_op *optab);
int					check_all_function(t_function *function, t_op *optab);
t_op				*get_good_optab(t_function *function, t_op *optab, int *i);
int					ft_namecmp(char *line, char *name, int *i);

t_op				*get_op_tab();
t_op				*get_ld();
t_op				*get_st();
t_op				*get_add();
t_op				*get_sub();
t_op				*get_and();
t_op				*get_or();
t_op				*get_xor();
t_op				*get_zjmp();
t_op				*get_ldi();
t_op				*get_sti();
t_op				*get_fork();
t_op				*get_lld();
t_op				*get_lldi();
t_op				*get_lfork();
t_op				*get_aff();
//DEGUG
int					print_struct(t_label *start);
int					print_op_tab(t_op *start);
#endif

#ifndef ASM_H
# define ASM_H

#include "define.h"

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef char		t_arg_type;


typedef struct		s_function
{
	int					ODC;
	int					pos;
	char				*line;
	struct s_op			*optab;
	struct s_function	*next;
}					t_function;


typedef struct		s_label
{
	char				*name;
	int					pos;
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
	int				label_size;
	struct s_op		*next;
}					t_op;


int					check_name_comment(int fd, char **name_str, char **comment_str);
int					check_format(char *line, char *str, int len);
int					parser(char *file);
char				*take_new_line(char *line);


int					ft_isspace(char c);
int					ft_strlen(const char *s);
char				*ft_strchr(char *s, int c);
int					tmp_name_strchr(char *line, char a);
char				*take_label_name(t_label *new, char *line);

unsigned short		b_swap_16(unsigned short value);
unsigned int		b_swap_32(unsigned int value);
int					add_function2(t_label *new, char *line, int j);
char				*ft_strdup(const char *s1);


int					ft_strlenchr(char *buffer, int a);
int					saveline(char *buffer, char **line, char **buf);
char				*ft_strjoin2(char *str, char *str2);
int					addbuff(char **buffer, int const fd, int *ret);
int					get_next_line(int const fd, char **line);

int					check_all_label(t_label *label, t_op *optab, t_label *start);
int					check_all_function(t_function *function, t_op *optab, t_label *lab);
int					check_arg(t_function *function, t_label *label, int *i, int nbrarg);
int					set_opcode(int type, t_function *function, int nbrarg);
t_op				*get_good_optab(t_function *function, t_op *optab, int *i);
int					ft_namecmp(char *line, char *name, int *i);

int					check_registre(char *line, int *i);
int					check_label(char *line, int *i, t_label *label);
int					check_nbr(char *line, int *i);
int					check_nbr2(char *line, int *i);

t_label				*read_label_function(int fd);
int					is_label(char *line);
t_label				*new_label(t_label *label, char *line);
int					new_function(t_label *label, char *line);
t_function 			*new_lst_function(char *line);

int					write_file(t_label *start, char *name, char *comment, char *file);
char				*set_cor_name(char *file);

int					write_reg(int fd, char *str, int *i);
int					write_dir(int fd, t_function *function, int *i);
int					write_dir_label(int fd, t_function *function, int *i, t_label *start);
int					write_nb(unsigned int nb, int fd, int size);
int					write_ind(int fd, char *str, int *i);
int					take_pos_label(t_label *label, char *line, int *i);

int					set_pos(t_label *start, int pos);
int					add_pos(t_function *function);

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

#endif

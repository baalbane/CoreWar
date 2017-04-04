/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:31:48 by baalbane          #+#    #+#             */
/*   Updated: 2017/04/04 16:42:17 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	write_header(int fd, char *name, char *comment, int size)
{
	int			i;
	t_header	header;

	header.magic = b_swap_32(COREWAR_EXEC_MAGIC);
	header.prog_size = b_swap_32((unsigned int)size);
	i = 6;
	while (name[++i] != '"')
		header.prog_name[i - 7] = name[i];
	while (i - 7 <= PROG_NAME_LENGTH + 3)
		header.prog_name[(i++) - 7] = 0;
	i = 9;
	while (comment[++i] != '"')
		header.comment[i - 10] = comment[i];
	while (i - 10 <= COMMENT_LENGTH + 1)
		header.comment[(i++) - 10] = 0;
	write(fd, &header, sizeof(t_header));
	return (1);
}

static	int	write_function(t_function *function, t_label *start, int fd)
{
	int		i;

	write_nb((unsigned int)function->optab->op_code, fd, 1);
	if (function->optab->octet_codage == 1)
		write_nb((unsigned int)function->ODC, fd, 1);
	i = 0;
	while (function->line[i] != ' ' && function->line[i] != SEPARATOR_CHAR)
		i++;
	while (function->line[i] != '\0')
	{
		if (function->line[i] == 'r')
			write_reg(fd, function->line, &i);
		else if (function->line[i] == DIRECT_CHAR
		&& function->line[i + 1] == LABEL_CHAR)
			write_dir_label(fd, function, &i, start);
		else if (function->line[i] == DIRECT_CHAR)
			write_dir(fd, function, &i);
		else if (function->line[i] == '-' || (function->line[i] >= '0'
		&& function->line[i] <= '9'))
			write_ind(fd, function->line, &i);
		else
			i++;
	}
	return (1);
}

int			write_file(t_label *start, char *name, char *comment, char *file)
{
	int			fd;
	int			size;
	t_label		*tmp_label;
	t_function	*tmp_function;

	tmp_label = NULL;
	tmp_function = NULL;
	size = set_pos(start, 0);
	file = set_cor_name(file);
	fd = open(file, O_WRONLY | O_CREAT);
	write_header(fd, name, comment, size);
	tmp_label = start;
	while (tmp_label != NULL)
	{
		tmp_function = tmp_label->function;
		while (tmp_function != NULL)
		{
			write_function(tmp_function, start, fd);
			tmp_function = tmp_function->next;
		}
		tmp_label = tmp_label->next;
	}
	return (1);
}

int			take_pos_label(t_label *label, char *line, int *i)
{
	int j;

	if (!label->name)
		label = label->next;
	while (label != NULL)
	{
		j = 0;
		while (label->name[j] != LABEL_CHAR && line[*i + j] == label->name[j])
			j++;
		if (label->name[j] == LABEL_CHAR && (line[*i + j] == ' '
		|| line[*i + j] == SEPARATOR_CHAR || line[*i + j] == '\0'))
		{
			(*i) += j;
			return (label->pos);
		}
		label = label->next;
	}
	printf("========\nERROR TAKE POS LABEL, NO LABEL FOUND   <==== PRINTF\n========\n");
	return (0);
}

char		*set_cor_name(char *file)
{
	char	*new;
	int		i;
	int		len;

	len = ft_strlen(file) + 2;
	new = malloc(sizeof(char) * (len + 1));
	i = -1;
	while (++i < len - 3)
		new[i] = file[i];
	new[i++] = 'c';
	new[i++] = 'o';
	new[i++] = 'r';
	new[i] = '\0';
	return (new);
}

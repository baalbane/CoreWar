/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:21:22 by baalbane          #+#    #+#             */
/*   Updated: 2017/04/06 15:13:47 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	parser_2(t_label *start, t_op *optab)
{
	t_label *tmp;

	tmp = start;
	while (tmp != NULL)
	{
		if (check_all_label(tmp, optab, start) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			parser(char *file)
{
	int		fd;
	char	*name;
	char	*comment;
	t_label	*start;
	t_op	*optab;

	if ((fd = open(file, O_RDONLY)) <= 0)
		return (-1);
	if (check_name_comment(fd, &name, &comment) == 0)
	{
		ft_putstr("Error: wrong \".name\" or \".comment\".\n", 2);
		return (0);
	}
	start = read_label_function(fd);
	close(fd);
	optab = get_op_tab();
	if (!parser_2(start, optab))
		return (-1);
	write_file(start, name, comment, file);
	free_optab(optab);
	free_label(start);
	return (1);
}

static char	*take_new_line_bis2(char *line, char *new, int j)
{
	if (j > 0 && new[j - 1] == ' ')
		new[j - 1] = '\0';
	if (new[0] == '\0')
	{
		free(new);
		new = NULL;
	}
	free(line);
	return (new);
}

static char	*take_new_line_bis(char *line, int i, int j)
{
	char	*new;

	new = malloc(sizeof(char) * (j + 1));
	i = 0;
	j = 0;
	while (line[i] != '\0' && line[i] != COMMENT_CHAR && line[i] != ';')
	{
		if (line[i] == '"')
		{
			new[j++] = line[i++];
			while (line[i] != '"' && line[i] != '\0')
				new[j++] = line[i++];
			if (line[i] == '"')
				new[j++] = line[i++];
		}
		while (ft_isspace(line[i]))
			i++;
		while (line[i] != '\0' && !ft_isspace(line[i])
		&& line[i] != COMMENT_CHAR && line[i] != '"' && line[i] != ';')
			new[j++] = line[i++];
		if (ft_isspace(line[i]))
			new[j++] = ' ';
	}
	new[j] = '\0';
	return (take_new_line_bis2(line, new, j));
}

char		*take_new_line(char *line)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line && line[i] != '\0' && line[i] != COMMENT_CHAR && line[i] != ';')
	{
		if (line[i] == '"')
		{
			i += 1 + 0 * j++;
			while (line[i] != '"' && line[i] != '\0')
				i += 1 + 0 * j++;
			if (line[i] == '"')
				i += 1 + 0 * j++;
		}
		while (ft_isspace(line[i]))
			i++;
		while (line[i] != '\0' && !ft_isspace(line[i])
		&& line[i] != COMMENT_CHAR && line[i] != '"' && line[i] != ';')
			i += 1 + 0 * j++;
		if (ft_isspace(line[i]))
			j++;
	}
	return (take_new_line_bis(line, i, j));
}

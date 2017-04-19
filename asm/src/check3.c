/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <baalbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:11:41 by baalbane          #+#    #+#             */
/*   Updated: 2017/04/19 16:07:57 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	verif_name_comment(int *name, char **str, char *line)
{
	if (*name != 0)
		return (0);
	*name = 1;
	*str = line;
	return (1);
}

int			check_name_comment(int fd, char **name_str, char **comment_str)
{
	char		*s;
	static	int	name = 0;
	static	int	comment = 0;

	while ((name == 0 || comment == 0) && get_next_line(fd, &s) > 0)
	{
		s = take_new_line(s);
		if (s != NULL && check_form(s, NAME_CMD_STRING, PROG_NAME_LENGTH))
		{
			if (!verif_name_comment(&name, name_str, s))
				return (0);
		}
		else if (s != NULL && check_form(s, COMMENT_CMD_STRING, COMMENT_LENGTH))
		{
			if (!verif_name_comment(&comment, comment_str, s))
				return (0);
		}
		else if (s != NULL)
		{
			free(s);
			return (0);
		}
	}
	return (name == 1 && comment == 1 ? 1 : 0);
}

int			check_form(char *line, char *str, int len)
{
	int		i;
	int		j;

	i = 0;
	while (line[i] != '\0' && str[i] != '\0' && line[i] == str[i])
		i++;
	if (str[i] != '\0')
		return (0);
	if (line[i] != ' ' || line[i + 1] != '"')
		return (0);
	i += 2;
	j = 0;
	while (line[i + j] != '\0' && line[i + j] != '"')
		j++;
	if (line[i + j] != '"' || line[i + j + 1] != '\0' || j - 1 >= len)
		return (0);
	return (1);
}

int			set_opcode(int type, t_function *function, int nbrarg)
{
	if (nbrarg == 0)
		function->odc += type * 64;
	else if (nbrarg == 1)
		function->odc += type * 16;
	else if (nbrarg == 2)
		function->odc += type * 4;
	else
		function->odc += type;
	return (1);
}

int			ft_putstr(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
	return (1);
}

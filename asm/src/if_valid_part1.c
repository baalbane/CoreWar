/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_valid_part1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 16:21:25 by ttridon           #+#    #+#             */
/*   Updated: 2016/11/24 15:52:07 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h>

int		check_format(char *line, char *string, int len)
{
	if (ft_strnequ(line, string, ft_strlen(string)))
	{
		char *tmp;

		line += ft_strlen(string);
		line = ft_strtrim(line);
		if (*line != '\"')
		{
			ft_strdel(&line);
			return (0);
		}
		tmp = line + 1;
		while (*tmp && *tmp != '\"')
			tmp++;
		if ((tmp - line - 1) > len)
		{
			ft_strdel(&line);
			return (0);
		}
		if (*tmp != '\"' || *(tmp + 1) != '\0')
		{
			ft_strdel(&line);
			return (0);
		}
		return (1);
	}
	return (0);
}

int		check_name_comment(int fd)
{
	char		*line;
	char		*tmp;
	static	int	name = 0;
	static	int	comment = 0;

	while ((name == 0 || comment == 0) && get_next_line(fd, &line))
	{
		tmp = ft_strtrim(line);
		if (check_format(tmp, NAME_CMD_STRING, PROG_NAME_LENGTH))
		{
			if (name != 0)
				return (error_name_comment(1, line, tmp));
			name = 1;
		}
		else if (check_format(tmp, COMMENT_CMD_STRING, COMMENT_LENGTH))
		{
			if (comment != 0)
				return (error_name_comment(2, line, tmp));
			comment = 1;
		}
		else if (*tmp != '\0' && *tmp != '#')
			return (error_name_comment(3, line, tmp));
		ft_strdel(&line);
		ft_strdel(&tmp);
	}
	return (1);
}

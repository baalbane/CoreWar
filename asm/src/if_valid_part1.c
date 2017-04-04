/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_valid_part1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 16:21:25 by ttridon           #+#    #+#             */
/*   Updated: 2017/04/04 16:19:29 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h>

int		check_format(char *line, char *str)
{
	int		i;

	i = 0;
	while (line[i] != '\0' && str[i] != '\0' && line[i] == str[i])
		i++;
	if (str[i] != '\0')
		return (0);
	if (line[i] != ' ' || line[i + 1] != '"')
	{
		printf("Error: No name after \".name\". \033[41m\033[33m<--CARE PRINTF\033[0m\n");
		return (-1);
	}
	i += 2;
	return (0);
}

int		check_name_comment(int fd)
{
	char		*line;
	char		*tmp;
	static int	name = 0;
	static int	comment = 0;

	while ((name == 0 || comment == 0) && get_next_line(fd, &line))
	{
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

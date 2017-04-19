/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:17:18 by baalbane          #+#    #+#             */
/*   Updated: 2017/04/04 17:00:40 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		ft_strlenchr(char *buffer, int a)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (a == 0)
		return (i);
	if (buffer[i] != '\0')
		i++;
	while (buffer[i + j] != '\0')
		j++;
	return (j);
}

int		saveline(char *buffer, char **line, char **buf)
{
	int		i;
	int		tmp;
	char	*newbuf;
	char	*newline;

	newline = malloc(sizeof(char) * (ft_strlenchr(buffer, 0) + 1));
	newbuf = malloc(sizeof(char) * (ft_strlenchr(buffer, 1) + 1));
	i = 0;
	tmp = -1;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		newline[i] = buffer[i];
		i++;
	}
	newline[i] = '\0';
	if (buffer[i] == '\n')
		i++;
	while (buffer[i + ++tmp] != '\0')
		newbuf[tmp] = buffer[i + tmp];
	newbuf[tmp] = '\0';
	free(buffer);
	*line = newline;
	*buf = newbuf;
	return (1);
}

char	*ft_strjoin2(char *str, char *str2)
{
	int		len[2];
	char	*new;

	len[0] = ft_strlen(str);
	len[1] = ft_strlen(str2);
	new = malloc(sizeof(char) * (len[0] + len[1] + 1));
	len[0] = 0;
	len[1] = 0;
	while (str[len[0]] != '\0')
	{
		new[len[0]] = str[len[0]];
		len[0]++;
	}
	while (str2[len[1]] != '\0')
	{
		new[len[0] + len[1]] = str2[len[1]];
		len[1]++;
	}
	new[len[0] + len[1]] = '\0';
	free(str);
	free(str2);
	return (new);
}

int		addbuff(char **buffer, int const fd, int *ret)
{
	char	*new;

	new = malloc(sizeof(char) * (BUFF_SIZE + 1));
	*ret = read(fd, new, BUFF_SIZE);
	if (*ret < 0)
	{
		free(new);
		return (-1);
	}
	new[*ret] = '\0';
	*buffer = ft_strjoin2(*buffer, new);
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	int				ret;
	static	char	*buffer = NULL;

	if (fd < 0 || !line)
		return (-1);
	if (buffer == NULL)
	{
		buffer = malloc(sizeof(char));
		buffer[0] = '\0';
	}
	ret = 1;
	while (ret > 0)
	{
		if (ft_strchr(buffer, '\n') != NULL)
			return (saveline(buffer, line, &buffer));
		if (addbuff(&buffer, fd, &ret) == -1)
			return (-1);
	}
	if (buffer[0] != '\0')
		return (saveline(buffer, line, &buffer));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:17:35 by baalbane          #+#    #+#             */
/*   Updated: 2017/04/07 16:41:09 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\v' || c == '\r'
	|| c == '\f' || c == '\t')
		return (1);
	return (0);
}

int		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] && s)
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	while (*s != c && *s)
		s++;
	if (*s == c)
		return (s);
	return (NULL);
}

int		tmp_name_strchr(char *line, char a)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != a)
		i++;
	if (line[i] == a)
		return (1);
	return (0);
}

char	*take_label_name(t_label *new, char *line)
{
	char	*name;
	int		j;
	int		i;

	j = 1;
	while (line[j - 1] != ':')
		j++;
	i = j;
	name = malloc(sizeof(char*) * (j + 1));
	name[j] = '\0';
	while (--j >= 0)
		name[j] = line[j];
	if (line[i] != '\0')
		add_function2(new, line, i);
	else
		free(line);
	return (name);
}

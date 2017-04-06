/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:17:35 by baalbane          #+#    #+#             */
/*   Updated: 2017/04/06 15:09:40 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

unsigned short	b_swap_16(unsigned short value)
{
	return ((value >> 8) | (value << 8));
}

unsigned int	b_swap_32(unsigned int value)
{
	return (b_swap_16(value & 0xffff) << 16) | (b_swap_16(value >> 16));
}

int				add_function2(t_label *new, char *line, int j)
{
	int		i;
	char	*function;

	i = 0;
	while (line[i + j] != '\0')
		i++;
	if (j != 0)
	{
		function = malloc(sizeof(char) * (i + 1));
		function[i] = '\0';
		while (--i >= 0)
			function[i] = line[i + j];
		function = take_new_line(function);
		new_function(new, function);
	}
	free(line);
	return (1);
}

char			*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int				ft_namecmp(char *line, char *name, int *i)
{
	*i = 0;
	while (line[*i] == name[*i])
		(*i)++;
	if (name[*i] == '\0' && line[*i] == ' ')
		return (1);
	return (0);
}

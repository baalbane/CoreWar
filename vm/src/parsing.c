/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:57:57 by ttridon           #+#    #+#             */
/*   Updated: 2017/02/09 18:07:46 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

static unsigned char	*ft_strdup_mod(unsigned char *line, unsigned int size)
{
	unsigned char	*new_line;
	unsigned int	i;

	new_line = (unsigned char *)malloc(sizeof(unsigned char) * size);
	i = 0;
	while (i < size)
	{
		new_line[i] = line[i];
		i++;
	}
	return (new_line);
}

static int		big_to_little_endian(int nbr)
{
	return ((nbr >> 24 & 0xff) | (nbr << 8 & 0xff0000)
		| (nbr >> 8 & 0xff00) | (nbr >> 24 & 0xff000000));
}

static void				create_champion(t_header *header, t_champion **champion)
{
	t_champion		*new_champion;
	t_champion		*tmp;
	static int		nb = 1;

	tmp = *champion;
	new_champion = (t_champion *)malloc(sizeof(t_champion));
	if (!(*champion))
		*champion = new_champion;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_champion;
	}
	new_champion->name = ft_strdup(header->name);
	new_champion->comment = ft_strdup(header->comment);
	new_champion->code = ft_strdup_mod(header->code,
		big_to_little_endian(header->size));
	new_champion->size = big_to_little_endian(header->size);
	new_champion->number = nb;
	new_champion->next = NULL;
	nb++;
}

int						parsing(char *file, t_champion **champion)
{
	t_header		*header;
	int				fd;
	int				ret;

	header = (t_header *)malloc(sizeof(t_header));
	fd = open(file, O_RDONLY);
	ret = read(fd, header, (sizeof(t_header)));
	create_champion(header, champion);
	free(header);
	return (0);
}

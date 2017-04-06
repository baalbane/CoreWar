/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:22:02 by ttridon           #+#    #+#             */
/*   Updated: 2017/03/28 16:25:07 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

unsigned char	*ft_unstrndup(unsigned char *line, unsigned int size)
{
	unsigned char	*new_line;
	unsigned int	i;

	if (!(new_line = (unsigned char *)malloc(sizeof(unsigned char)
		* (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_line[i] = line[i];
		i++;
	}
	return (new_line);
}

int				if_valid_number(t_champion *champion, int champion_number)
{
	while (champion)
	{
		if (champion->number == champion_number)
			return (1);
		champion = champion->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 18:50:04 by ttridon           #+#    #+#             */
/*   Updated: 2017/02/06 16:34:24 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	arena_init(unsigned char *arena, t_champion *champion, t_game *game)
{
	int		i;
	int		j;
	int		pos;
	int		ratio;

	ft_bzero(arena, MEM_SIZE);
	ratio = 0;
	pos = MEM_SIZE / game->nb_players;
	while (champion)
	{
		j = 0;
		i = pos * ratio;
		while (j < champion->size)
		{
			arena[i] = champion->code[j];
			i++;
			j++;
		}
		ratio++;
		champion = champion->next;
	}
	// i = 0;
	// while (i < MEM_SIZE)
	// {
	// 	printf("%02x ", arena[i]);
	// 	i++;
	// 	if (i % 64 == 0)
	// 		printf("\n");
	// }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 11:01:18 by ttridon           #+#    #+#             */
/*   Updated: 2017/03/28 16:15:04 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	write_arena(unsigned char *arena, int pc, unsigned int value,
	int size_value)
{
	pc -= 1;
	if (pc < 0)
		pc += MEM_SIZE;
	while (size_value)
	{
		arena[(pc + size_value) % MEM_SIZE] = value % 256;
		value = value / 256;
		size_value--;
	}
}

void	dump_arena(unsigned char *arena)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		printf("%02x ", arena[i]);
		i++;
		if (i % 64 == 0)
			printf("\n");
	}
}

int		init_arena(unsigned char *arena, t_game *game)
{
	t_champion	*tmp_champion;
	int			nb_player;
	int			pos_arena;
	int			j;

	ft_bzero(arena, MEM_SIZE);
	tmp_champion = game->champion;
	nb_player = 0;
	set_champion_position(game);
	while (tmp_champion)
	{
		j = 0;
		pos_arena = tmp_champion->position;
		while (j < tmp_champion->size_code)
		{
			arena[pos_arena] = tmp_champion->code[j];
			pos_arena++;
			j++;
		}
		nb_player++;
		tmp_champion = tmp_champion->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:56:49 by ttridon           #+#    #+#             */
/*   Updated: 2017/02/14 17:34:14 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		get_arg(unsigned char *arena, int PC, int size)
{
	int		i;
	int		nb;

	i = -1;
	nb = 0;
	while (++i < size)
	{
		if (PC+i > MEM_SIZE)
			i -= MEM_SIZE;
		nb = nb * 256 + arena[PC+i];
	}
	return (nb);
}

void		live(unsigned char *arena, t_process *process, t_champion *champion,
	 t_game *game)
{
	int		nb;
	int		i;
	int		arg;

	i = 0;
	nb = 0;
	if (process->cooldown == -1)
		process->cooldown = 10;
	else
	{
		process->live = 1;
		//game->winner = process->reg[0];
		game->nbr_live++;
		printf("==%d==\n", (arg=get_arg(arena, process->PC + 1, 4)));
		while (champion)
		{
			if (champion->number == arg)
			{
				game->winner = champion->number;
				break ;
			}
			champion = champion->next;
		}
		process->PC += DIR_SIZE + 1;
	}
}

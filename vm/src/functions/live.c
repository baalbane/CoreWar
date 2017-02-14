/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:56:49 by ttridon           #+#    #+#             */
/*   Updated: 2017/02/14 17:15:51 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	big_to_little_endian(int *nbr)
{
	return ((*nbr >> 24 & 0xff) | (*nbr << 8 & 0xff0000)
		| (*nbr >> 8 & 0xff00) | (*nbr >> 24 & 0xff000000));
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
		arg = big_to_little_endian((int *)(&arena[process->PC + 1]));
		// printf("arg: [%d] | process: [%d]\n", arg, process->PC);
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

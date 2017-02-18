/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:56:49 by ttridon           #+#    #+#             */
/*   Updated: 2017/02/18 15:44:47 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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
		arg = get_value(arena, process, DIR_SIZE);
		printf("Joueur: %d | arg: %d\n", process->reg[0], arg);
		while (champion)
		{
			if (champion->number == arg)
			{
				game->winner = champion->number;
				break ;
			}
			champion = champion->next;
		}
		process->cooldown = -1;
		process->PC++;
	}
}

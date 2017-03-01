/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:38:33 by ttridon           #+#    #+#             */
/*   Updated: 2017/03/01 16:50:06 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	new_process(unsigned char *arena, t_process *process, t_game *game)
{
	t_process	*new_process;
	int			i;

	new_process = (t_process *)malloc(sizeof(t_process));
	new_process->next = game->start_process;
	game->start_process = new_process;
	new_process->live = 0;
	new_process->carry = 0;
	new_process->cooldown = -1;
	i = 0;
	while (i < REG_NUMBER)
	{
		new_process->reg[i] = 0;
		i++;
	}
	new_process->champion = process->champion;
	new_process->reg[0] = process->champion->number;
	new_process->PC = move_PC(process->PC, arena[process->PC + 1] * 256 + arena[process->PC + 2]);
}

void	ft_fork(unsigned char *arena, t_process *process, t_game *game)
{
	if (process->cooldown == -1)
	{
		process->cooldown = 800;
		return ;
	}
	process->cooldown = -1;
	new_process(arena, process, game);
	process->PC = move_PC(process->PC, 2);
	//}
}

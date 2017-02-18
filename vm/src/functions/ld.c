/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:22:12 by ttridon           #+#    #+#             */
/*   Updated: 2017/02/18 16:54:49 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

//(arena[process->PC + 1] && 0x192) ||

void	ld(unsigned char *arena, t_process *process, t_champion *champion,
	 t_game *game)
{
	int		arg[MAX_ARG_NUMBER];

	if (process->cooldown == -1)
	{
		process->cooldown = 5;
		return ;
	}
	process->cooldown = -1;
	if (arena[process->PC + 1] && 0x192 == 0x01
		|| arena[process->PC +1] && 0x192 == 0x00
		|| arena[process->PC + 1] && 0x128 != 0x01)
		return ;
	get_args(arena, PC, tab, dir_size);
	if (arg[1] > REG_NUMBER)
		return ;
	process->reg[arg[1]] = arg[0];
}

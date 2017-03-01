/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:48:50 by ttridon           #+#    #+#             */
/*   Updated: 2017/03/01 15:39:39 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	sti(unsigned char *arena, t_process *process)
{
	int		arg[MAX_ARGS_NUMBER];
	int		tmp_PC;

	if (process->cooldown == -1)
	{
		process->cooldown = 25;
		return ;
	}
	process->cooldown = -1;
	process->PC = move_PC(process->PC, 1);
	tmp_PC = process->PC;
	process->carry = 0;
	//if (arena[process->PC] >> 6 != 0 && (arena[process->PC] >> 4 & 0x03) != 0 && (arena[process->PC] >> 2 & 0x03) == REG_CODE)
	//{
		get_args(arena, process, arg, 2);
		if (check_reg(arena[tmp_PC], arg)
		&& arena[tmp_PC] >> 6 == REG_CODE && (arena[tmp_PC] >> 4 & 0x03) != 0 && (arena[tmp_PC] >> 2 & 0x03) != IND_CODE && (arena[tmp_PC] >> 2 & 0x03) != 0)
		{
			if ((arena[tmp_PC] >> 4 & 0x03) == IND_CODE)
				arg[1] = get_ind(arena, move_PC(tmp_PC - 1, arg[1]));
			else if ((arena[tmp_PC] >> 4 & 0x03) == REG_CODE)
				arg[1] = process->reg[arg[1]];
			if ((arena[tmp_PC] >> 2 & 0x03) == REG_CODE)
				arg[2] = process->reg[arg[2]];
			printf("PC: %d | arg1: %d | arg2: %d\n", process->PC, arg[1], arg[2]);
			rewrite_arena(arena, tmp_PC + arg[1] + arg[2] - 1, process->reg[arg[0]]);
			process->carry = 1;
		}
	//}
}

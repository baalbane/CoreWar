/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:42:28 by ttridon           #+#    #+#             */
/*   Updated: 2017/02/24 18:42:59 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	or(unsigned char *arena, t_process *process)
{
	int		arg[MAX_ARGS_NUMBER];
	int		tmp_PC;

	if (process->cooldown == -1)
	{
		process->cooldown = 6;
		return ;
	}
	process->cooldown = -1;
	process->PC = move_PC(process->PC, 1);
	tmp_PC = process->PC;
	process->carry = 0;
	//if (arena[process->PC] >> 6 != 0 && (arena[process->PC] >> 4 & 0x03) != 0 && (arena[process->PC] >> 2 & 0x03) == REG_CODE)
	//{
		get_args(arena, process, arg, DIR_SIZE);
		if (check_reg(arena[tmp_PC], arg)
		&& arena[tmp_PC] >> 6 != 0 && (arena[tmp_PC] >> 4 & 0x03) != 0 && (arena[tmp_PC] >> 2 & 0x03) == REG_CODE)
		{
			if (arena[tmp_PC] >> 6 == IND_CODE)
				arg[0] = get_ind(arena, move_PC(tmp_PC - 1, arg[0]));
			else if (arena[tmp_PC] >> 6 == REG_CODE)
					arg[0] = process->reg[arg[0]];
			if ((arena[tmp_PC] >> 4 & 0x03) == IND_CODE)
				arg[1] = get_ind(arena, move_PC(tmp_PC - 1, arg[1]));
			else if ((arena[tmp_PC] >> 4 & 0x03) == REG_CODE)
				arg[1] = process->reg[arg[1]];
			process->reg[arg[2]] = arg[0] | arg[1];
			process->carry = 1;
			printf("or result: %x\n", process->reg[arg[2]]);
		}
	//}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 16:36:12 by ttridon           #+#    #+#             */
/*   Updated: 2017/02/24 18:32:55 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	add(unsigned char *arena, t_process *process)
{
	int		arg[MAX_ARGS_NUMBER];
	int		tmp_PC;

	if (process->cooldown == -1)
	{
		process->cooldown = 10;
		return ;
	}
	process->cooldown = -1;
	process->PC = move_PC(process->PC, 1);
	tmp_PC = process->PC;
	process->carry = 0;
	get_args(arena, process, arg, DIR_SIZE);
	if (check_reg(arena[tmp_PC], arg)
	&& arena[tmp_PC] >> 6 == REG_CODE && (arena[tmp_PC] >> 4 & 0x03) == REG_CODE && (arena[tmp_PC] >> 2 & 0x03) == REG_CODE)
	{
		process->reg[arg[2]] = process->reg[arg[0]] + process->reg[arg[1]];
		process->carry = 1;
	}
}

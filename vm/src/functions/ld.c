/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:22:12 by ttridon           #+#    #+#             */
/*   Updated: 2017/02/21 18:34:21 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ld(unsigned char *arena, t_process *process)
{
	int		arg[MAX_ARGS_NUMBER];
	int		tmp_PC;

	if (process->cooldown == -1)
	{
		process->cooldown = 5;
		return ;
	}
	process->cooldown = -1;
	process->PC = move_PC(process->PC, 1);
	tmp_PC = process->PC;
	if (arena[process->PC] >> 6 != REG_CODE && (arena[process->PC] >> 6) != 0 && (arena[process->PC] >> 4 & 0x03) == REG_CODE)
	{
		get_args(arena, process, arg, DIR_SIZE);
		printf("Avant: %d\n", process->reg[arg[1]]);
		if ((arena[tmp_PC] >> 6) == IND_CODE)
			arg[0] = get_ind(arena, move_PC(tmp_PC - 1, arg[0]));
		if (check_reg(arena[tmp_PC], arg))
			process->reg[arg[1]] = arg[0];
			printf("Apres: %d\n", process->reg[arg[1]]);
	}
}

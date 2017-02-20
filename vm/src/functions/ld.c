/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:22:12 by ttridon           #+#    #+#             */
/*   Updated: 2017/02/20 19:19:46 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	ld(unsigned char *arena, t_process *process)
{
	int		arg[MAX_ARGS_NUMBER];

	if (process->cooldown == -1)
	{
		process->cooldown = 5;
		return ;
	}
	process->cooldown = -1;
	process->PC = move_PC(process->PC, 1);
	if (arena[process->PC] >> 6 != MASK_REG && (arena[process->PC] >> 6) != 0 && (arena[process->PC] >> 4 & 0x03) == 0x01)
	{
		get_args(arena, process, arg, DIR_SIZE);
		if (arg[1] >= 0 && arg[1] < REG_NUMBER)
		{
			printf("Avant: %d\n", arg[0]);
			process->reg[arg[1]] = arg[0];
			printf("Apres: %d\n", process->reg[arg[1]]);
		}
	}
	process->PC = move_PC(process->PC, 1);
}

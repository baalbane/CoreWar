/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 13:08:59 by ttridon           #+#    #+#             */
/*   Updated: 2017/03/01 15:39:08 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		big_to_little_endian(int nbr)
{
	return ((nbr >> 24 & 0xff) | (nbr << 8 & 0xff0000)
		| (nbr >> 8 & 0xff00) | (nbr << 24 & 0xff000000));
}

void	ldi(unsigned char *arena, t_process *process)
{
	int		arg[MAX_ARGS_NUMBER];
	int		tmp_PC;
	int		*value;
	int		value_bis;

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
		&& arena[tmp_PC] >> 6 != 0 && (arena[tmp_PC] >> 4 & 0x03) != 0 && (arena[tmp_PC] >> 4 & 0x03) != IND_CODE && (arena[tmp_PC] >> 2 & 0x03) == REG_CODE)
		{
			if (arena[tmp_PC] >> 6 == IND_CODE)
				arg[0] = get_ind(arena, move_PC(tmp_PC - 1, arg[0]));
			else if (arena[tmp_PC] >> 6 == REG_CODE)
				arg[0] = process->reg[arg[0]];
			if ((arena[tmp_PC] >> 4 & 0x03) == REG_CODE)
				arg[1] = process->reg[arg[1]];
			value = (int *)&arena[tmp_PC + arg[0] + arg[1] - 1];
			value_bis = big_to_little_endian(*value);
			// printf("Value: %x | Value_bis: %x\n", *value, value_bis);
			// printf("Value: %x\n", value_bis);
			process->reg[arg[2]] = big_to_little_endian(*value);
			printf("Reg: %d\n", process->reg[0]);
			process->carry = 1;
		}
	//}
}

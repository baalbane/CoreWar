/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:22:12 by ttridon           #+#    #+#             */
/*   Updated: 2017/02/24 16:32:43 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	st(unsigned char *arena, t_process *process)
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
	if (arena[process->PC] >> 6 == REG_CODE && ((arena[process->PC] >> 4) & 0x03) != 0 && (arena[process->PC] >> 4 & 0x03) != DIR_CODE)
	{
		get_args(arena, process, arg, DIR_SIZE);

		if (check_reg(arena[tmp_PC], arg))
		{
			printf("Atmp %d\n", arena[tmp_PC] >> 4 & 0x03);
			if ((arena[tmp_PC] >> 4 & 0x03) == IND_CODE)
				rewrite_arena(arena, tmp_PC - 1 + arg[1], process->reg[arg[0]]);
			else
				process->reg[arg[1]] = process->reg[arg[0]];
			printf("Apres: %d\n", process->reg[arg[1]]);
		}
	}
}

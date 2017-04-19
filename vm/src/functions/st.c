/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:41:29 by ttridon           #+#    #+#             */
/*   Updated: 2017/04/05 16:25:03 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		cw_st(unsigned char *arena, t_process *process, t_game *game)
{
	int		params[MAX_ARGS_NUMBER];
	int		oct_codage;

	if (cooldown(process, ST_COOLDOWN) && game)
		return (0);
	oct_codage = reverse_oct_codage(arena[process->pc + 1]);
	if ((FIRST_OCT == REG_CODE && SECOND_OCT != 0 && SECOND_OCT != DIR_CODE))
	{
		if (!get_params(arena, process->pc + 1, DIR_SIZE, params))
		{
			if (SECOND_OCT == IND_CODE)
				write_arena(arena, (process->pc + params[1])
					% MEM_SIZE, process->reg[params[0]], REG_SIZE);
			else
				process->reg[params[1]] = process->reg[params[0]];
			process->carry = 1;
		}
		else
			process->carry = 0;
	}
	else
		process->carry = 0;
	move_process(process, jump_params(oct_codage, DIR_SIZE) + 1);
	return (0);
}

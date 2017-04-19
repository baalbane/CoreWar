/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:30:24 by ttridon           #+#    #+#             */
/*   Updated: 2017/04/05 17:05:16 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	cw_sti_bis(int oct_codage, int *params,
	t_process *process, unsigned char *arena)
{
	if (SECOND_OCT == REG_CODE)
		params[1] = process->reg[params[1]];
	if (SECOND_OCT == IND_CODE)
		params[1] = get_value(arena, process->pc + params[1], 4);
	if (THIRD_OCT == REG_CODE)
		params[2] = process->reg[params[2]];
	write_arena(arena, (process->pc + params[1]
		+ params[2]) % IDX_MOD, process->reg[params[0]], REG_SIZE);
	process->carry = 1;
}

int			cw_sti(unsigned char *arena, t_process *process, t_game *game)
{
	int		params[MAX_ARGS_NUMBER];
	int		oct_codage;

	if (cooldown(process, STI_COOLDOWN) && game)
		return (0);
	oct_codage = reverse_oct_codage(arena[process->pc + 1]);
	if ((FIRST_OCT == REG_CODE && SECOND_OCT != 0 && THIRD_OCT != 0
		&& THIRD_OCT != IND_CODE))
	{
		if (!get_params(arena, process->pc + 1, DIR_SIZE / 2, params))
			cw_sti_bis(oct_codage, params, process, arena);
		else
			process->carry = 0;
	}
	else
		process->carry = 0;
	move_process(process, jump_params(oct_codage, DIR_SIZE / 2) + 1);
	return (0);
}

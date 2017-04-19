/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:05:30 by ttridon           #+#    #+#             */
/*   Updated: 2017/04/05 17:02:55 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	cw_or_bis(int oct_codage, int *params,
	t_process *process, unsigned char *arena)
{
	if (FIRST_OCT == REG_CODE)
		params[0] = process->reg[params[0]];
	else if (FIRST_OCT == IND_CODE)
		params[0] = get_value(arena, process->pc + params[0], 4);
	if (SECOND_OCT == REG_CODE)
		params[1] = process->reg[params[1]];
	else if (SECOND_OCT == IND_CODE)
		params[1] = get_value(arena, process->pc + params[1], 4);
	process->reg[params[2]] = params[0] | params[1];
	process->carry = 1;
}

int			cw_or(unsigned char *arena, t_process *process, t_game *game)
{
	int		params[MAX_ARGS_NUMBER];
	int		oct_codage;

	if (cooldown(process, OR_COOLDOWN) && game)
		return (0);
	oct_codage = reverse_oct_codage(arena[process->pc + 1]);
	if ((FIRST_OCT != 0 && SECOND_OCT != 0 && THIRD_OCT == REG_CODE))
	{
		if (!get_params(arena, process->pc + 1, DIR_SIZE, params))
			cw_or_bis(oct_codage, params, process, arena);
		else
			process->carry = 0;
	}
	else
		process->carry = 0;
	move_process(process, jump_params(oct_codage, DIR_SIZE) + 1);
	return (0);
}

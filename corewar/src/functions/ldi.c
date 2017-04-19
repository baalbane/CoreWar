/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:29:55 by ttridon           #+#    #+#             */
/*   Updated: 2017/04/05 16:58:56 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	cw_ldi_bis(int oct_codage, int *params,
	t_process *process, unsigned char *arena)
{
	if (FIRST_OCT == IND_CODE)
		params[0] = get_value(arena, process->pc + params[0], 4);
	else if (FIRST_OCT == REG_CODE)
		params[0] = process->reg[params[0]];
	if (SECOND_OCT == REG_CODE)
		params[1] = process->reg[params[1]];
	process->reg[params[2]] = get_value(arena, params[0]
		+ params[1], 4);
	process->carry = 1;
}

int			cw_ldi(unsigned char *arena, t_process *process, t_game *game)
{
	int		params[MAX_ARGS_NUMBER];
	int		oct_codage;

	if (cooldown(process, LDI_COOLDOWN) && game)
		return (0);
	oct_codage = reverse_oct_codage(arena[process->pc + 1]);
	if ((FIRST_OCT != 0 && SECOND_OCT != 0
		&& SECOND_OCT != IND_CODE) && THIRD_OCT == REG_CODE)
	{
		if (!get_params(arena, process->pc + 1, DIR_SIZE / 2, params))
			cw_ldi_bis(oct_codage, params, process, arena);
		else
			process->carry = 0;
	}
	else
		process->carry = 0;
	move_process(process, jump_params(oct_codage, DIR_SIZE / 2) + 1);
	return (0);
}

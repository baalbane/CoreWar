/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:30:44 by ttridon           #+#    #+#             */
/*   Updated: 2017/04/05 16:03:06 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		cw_aff(unsigned char *arena, t_process *process, t_game *game)
{
	int		params[MAX_ARGS_NUMBER];
	int		oct_codage;

	if (cooldown(process, AFF_COOLDOWN) && game)
		return (0);
	oct_codage = reverse_oct_codage(arena[process->pc + 1]);
	if (FIRST_OCT == REG_CODE)
	{
		if (!get_params(arena, process->pc + 1, DIR_SIZE, params))
		{
			printf("%c\n", process->reg[params[0]] % 256);
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

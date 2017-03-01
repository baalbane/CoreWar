/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 18:40:28 by ttridon           #+#    #+#             */
/*   Updated: 2017/03/01 14:59:56 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static short		big_to_little_endian(short nbr)
{
	return ((nbr >> 8 & 0xff) | (nbr << 8 & 0xff00));
}

void	zjmp(unsigned char *arena, t_process *process)
{
	short	*value;
	short	value_bis;

	if (process->cooldown == -1)
	{
		process->cooldown = 20;
		return ;
	}
	process->cooldown = -1;
	if (process->carry)
	{
		value = (short *)&arena[process->PC + 1];
		value_bis = big_to_little_endian(*value);
		process->PC = move_PC(process->PC, arena[process->PC + 1] * 256 + arena[process->PC + 2]);
	}
}

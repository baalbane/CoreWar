/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:05:35 by ttridon           #+#    #+#             */
/*   Updated: 2017/04/05 16:24:13 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		cw_zjmp(unsigned char *arena, t_process *process, t_game *game)
{
	if (cooldown(process, ZJMP_COOLDOWN) && game)
		return (0);
	if (process->carry)
		move_process(process,
			(short)get_value(arena, process->pc + 1, 2) % IDX_MOD);
	else
		move_process(process, DIR_SIZE / 2 + 1);
	return (0);
}

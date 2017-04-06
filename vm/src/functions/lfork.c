/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:28:35 by ttridon           #+#    #+#             */
/*   Updated: 2017/04/05 16:22:57 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		cw_lfork(unsigned char *arena, t_process *process, t_game *game)
{
	int		params;

	if (cooldown(process, LFORK_COOLDOWN) && game)
		return (0);
	params = get_value(arena, process->pc + 1, 4);
	new_process(game->champion, process, game);
	game->process_list->pc += params % MEM_SIZE;
	move_process(process, DIR_SIZE / 2 + 1);
	return (0);
}

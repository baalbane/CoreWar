/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:30:27 by ttridon           #+#    #+#             */
/*   Updated: 2017/04/05 16:22:42 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		cw_fork(unsigned char *arena, t_process *process, t_game *game)
{
	int		params;

	if (cooldown(process, FORK_COOLDOWN) && game)
		return (0);
	params = get_value(arena, process->pc + 1, 2);
	new_process(game->champion, process, game);
	game->process_list->pc += (params % MEM_SIZE) % IDX_MOD;
	move_process(process, DIR_SIZE / 2 + 1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 14:19:40 by ttridon           #+#    #+#             */
/*   Updated: 2017/04/05 16:23:02 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		cw_live(unsigned char *arena, t_process *process, t_game *game)
{
	t_champion	*tmp_champion;
	int			value;

	if (cooldown(process, LIVE_COOLDOWN))
		return (0);
	process->live = 1;
	game->nbr_live++;
	value = get_value(arena, process->pc + 1, 4);
	tmp_champion = game->champion;
	while (tmp_champion)
	{
		if (tmp_champion->number == value)
		{
			game->winner = tmp_champion;
			break ;
		}
		tmp_champion = tmp_champion->next;
	}
	move_process(process, DIR_SIZE + 1);
	return (0);
}

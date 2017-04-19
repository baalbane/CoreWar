/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 11:00:54 by ttridon           #+#    #+#             */
/*   Updated: 2017/04/07 15:59:36 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	set_death(t_game *game)
{
	if (game->nbr_live > NBR_LIVE || ++game->nbr_check > MAX_CHECKS)
	{
		if (game->cycle_to_die < CYCLE_DELTA)
			game->cycle_to_die = 0;
		else
			game->cycle_to_die -= CYCLE_DELTA;
		game->nbr_check = 0;
	}
	game->nbr_live = 0;
}

static int	game_loop_bis(unsigned char *arena, t_game *game,
	t_process *process_list)
{
	while (process_list)
	{
		if (exe_process(arena, process_list, game))
			return (1);
		process_list = process_list->next;
	}
	return (0);
}

int			game_loop(unsigned char *arena, t_game *game)
{
	unsigned int	cycle;
	unsigned int	reaper;

	game->winner = NULL;
	game->cycle_to_die = CYCLE_TO_DIE;
	game->nbr_live = 0;
	game->nbr_check = 0;
	cycle = 1;
	reaper = 1;
	while (game->process_list)
	{
		if (cycle == game->dump)
			return (1);
		if (game_loop_bis(arena, game, game->process_list))
			return (1);
		if (reaper >= game->cycle_to_die)
		{
			kill_process(game);
			set_death(game);
			reaper = 0;
		}
		cycle++;
		reaper++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:07:13 by ttridon           #+#    #+#             */
/*   Updated: 2017/02/06 18:48:53 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
//gerer CYCLE_TO_DIE - CYCLE_DELTA - MAX_CHECKS.
static void process_kill(int *death, t_process **process, t_process **start,
	t_game *game)
{
	t_process *tmp;
	t_process	*prev;

	prev = NULL;
	tmp = *process;
	while (tmp)
	{
		if (tmp->live == 0)
		{
			if (prev == NULL)
				*start = tmp->next;
			else
				prev->next = tmp->next;
			free(tmp);
		}
		else
		{
			tmp->live = 0;
			prev = tmp;
		}
		tmp = tmp->next;
	}
	*process = *start;
}

static void new_process(int nb, t_champion *champion, t_process **process,
	t_game *game)
{
	t_process	*new_process;
	int			i;

	new_process = (t_process *)malloc(sizeof(t_process));
	if (*process)
		new_process->next = *process;
	else
		new_process->next = NULL;
	*process = new_process;
	new_process->live = 0;
	new_process->carry = 0;
	new_process->cooldown = 0;
	i = 0;
	while (i < REG_NUMBER)
	{
		new_process->reg[i] = 0;
		i++;
	}
	new_process->reg[0] = champion->number;
	new_process->PC = (MEM_SIZE / game->nb_players) * nb;
}

static void process_init(t_champion *champion, t_process **process,
	t_game *game)
{
	int		nb;

	nb = 0;
	while (champion)
	{
		new_process(nb, champion, process, game);
		nb++;
		champion = champion->next;
	}
}

void game_loop(unsigned char *arena, t_champion *champion, t_game *game)
{
	t_process	*process;
	t_process	*start;
	int			cycle;
	int			death;

	process = NULL;
	process_init(champion, &process, game);
	cycle = 0;
	death = game->cycle_to_die;
	start = process;
	while (process && game->dump != cycle)
	{
		process_exe();
		if (process == NULL || (process = process->next) == NULL)
		{
			process = start;
			cycle++;
		}
		if (cycle == death)
			process_kill(&death, &process, &start, game);
	}
}

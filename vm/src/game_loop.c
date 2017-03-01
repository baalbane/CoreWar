/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:07:13 by ttridon           #+#    #+#             */
/*   Updated: 2017/03/01 17:01:09 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	process_exe(unsigned char *arena, t_process *process, t_champion *champion, t_game *game)
{
	void (*tab_op[15])(unsigned char* arena, t_process *process) = {
		ld,
		st,
		add,
		sub,
		and,
		or,
		xor,
		zjmp,
		ldi,
		sti
	};

	if (process->cooldown > 0)
		process->cooldown--;
	else if (arena[process->PC] >= 2 && arena[process->PC] <= 11)
	{
		printf("Launch function %d\n", arena[process->PC]);
		tab_op[arena[process->PC] - 2](arena, process);
	}
	else if (arena[process->PC] >= 13 && arena[process->PC] <= 12)
	{
		printf("Launch function %d\n", arena[process->PC]);
		tab_op[arena[process->PC] - 3](arena, process);
	}
	else if (arena[process->PC] == 1)
		live(arena, process, champion, game);
	else if (arena[process->PC] == 12)
		ft_fork(arena, process, game);
	else
		process->PC = move_PC(process->PC, 1);
}

static void	time_to_die(t_game *game)
{
	if (game->nbr_live > NBR_LIVE || ++game->check > MAX_CHECKS)
	{
		game->cycle_to_die -= CYCLE_DELTA;
		game->check = 0;
	}
	game->nbr_live = 0;
}

static void	process_kill(t_process **process)
{
	t_process	*tmp;
	t_process	*prev;

	prev = NULL;
	tmp = *process;
	while (tmp)
	{
		// printf("Process: %d | Live: %d\n", tmp->reg[0], tmp->live);
		if (tmp->live == 0)
		{
			if (prev == NULL)
				*process = tmp->next;
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
}

static void	new_process(int nb, t_champion *champion, t_process **process, t_game *game)
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
	new_process->cooldown = -1;
	new_process->champion = champion;
	i = 0;
	while (i < REG_NUMBER)
	{
		new_process->reg[i] = 0;
		i++;
	}
	new_process->reg[0] = champion->number;
	new_process->PC = (MEM_SIZE / game->nb_players) * nb;
}

static void	process_init(t_champion *champion, t_process **process,
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
	game->start_process = *process;
}

void		game_loop(unsigned char *arena, t_champion *champion, t_game *game)
{
	t_process	*process;
	t_process	*tmp;
	int			cycle;
	int			death;

	process = NULL;
	process_init(champion, &process, game);
	cycle = 0;
	death = game->cycle_to_die;
	while (game->start_process && game->dump != cycle)
	{
		tmp = game->start_process;
		// if (process->PC == 50)
		// 	arena_aff(arena);
		//if (process->PC < 100)
		// printf("POS: %d\n", process->PC);
		while (tmp)
		{
			if (tmp->next != NULL)
				printf("toto WIN !\n");
			process_exe(arena, tmp, champion, game);
			tmp = tmp->next;
		}
		if (cycle == death)
		{
			// printf("Time to Die->Cycle: %d\n", cycle);
			process_kill(&game->start_process);
			time_to_die(game);
			death += game->cycle_to_die;
		}
		cycle++;
	}
	printf("END\n");
}

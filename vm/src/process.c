/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 14:52:52 by ttridon           #+#    #+#             */
/*   Updated: 2017/03/28 16:42:59 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				(*g_tab_op[16])(unsigned char *arena, t_process *process,
	t_game *game) = {
	cw_live,
	cw_ld,
	cw_st,
	cw_add,
	cw_sub,
	cw_and,
	cw_or,
	cw_xor,
	cw_zjmp,
	cw_ldi,
	cw_sti,
	cw_fork,
	cw_lld,
	cw_lldi,
	cw_lfork,
	cw_aff
};

void			move_process(t_process *process, int size)
{
	process->pc = (process->pc + size) % MEM_SIZE;
	if (process->pc < 0)
		process->pc += MEM_SIZE;
}

int				exe_process(unsigned char *arena, t_process *process,
	t_game *game)
{
	if (arena[process->pc] >= 1 && arena[process->pc] <= 16)
	{
		if (g_tab_op[arena[process->pc] - 1](arena, process, game))
			return (1);
	}
	else
		move_process(process, 1);
	return (0);
}

static void		copy_process(t_process *process, t_game *game)
{
	int		i;

	game->process_list->live = process->live;
	game->process_list->carry = process->carry;
	game->process_list->pc = process->pc;
	i = 0;
	while (i < REG_NUMBER)
	{
		game->process_list->reg[i] = process->reg[i];
		i++;
	}
}

int				new_process(t_champion *champion, t_process *process,
	t_game *game)
{
	t_process	*new_process;
	int			i;

	if (!(new_process = (t_process *)malloc(sizeof(t_process))))
		return (1);
	new_process->next = game->process_list;
	game->process_list = new_process;
	if (process)
		copy_process(process, game);
	else
	{
		new_process->live = 0;
		new_process->carry = 0;
		i = 0;
		while (i < REG_NUMBER)
		{
			new_process->reg[i] = 0;
			i++;
		}
		new_process->reg[0] = champion->number;
	}
	new_process->cooldown = 0;
	new_process->pc = champion->position;
	return (0);
}

int				init_process(t_champion *champion, t_game *game)
{
	int			nb;

	game->process_list = NULL;
	nb = 0;
	while (champion)
	{
		if (new_process(champion, NULL, game))
			return (1);
		nb++;
		champion = champion->next;
	}
	return (0);
}

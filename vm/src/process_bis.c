/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:21:59 by ttridon           #+#    #+#             */
/*   Updated: 2017/03/28 16:27:41 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		kill_process_bis(t_game *game,
	t_process *tmp_process, t_process *prev_process)
{
	while (tmp_process)
	{
		if (tmp_process->live == 0)
		{
			if (!prev_process)
			{
				game->process_list = tmp_process->next;
				free(tmp_process);
				tmp_process = game->process_list;
			}
			else
			{
				prev_process->next = tmp_process->next;
				free(tmp_process);
				tmp_process = prev_process->next;
			}
		}
		else
		{
			tmp_process->live = 0;
			prev_process = tmp_process;
			tmp_process = tmp_process->next;
		}
	}
}

void			kill_process(t_game *game)
{
	t_process *prev_process;
	t_process *tmp_process;

	prev_process = NULL;
	tmp_process = game->process_list;
	kill_process_bis(game, tmp_process, prev_process);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:07:13 by ttridon           #+#    #+#             */
/*   Updated: 2017/01/26 18:04:46 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void process_init(/* arguments */) {
	/* code */
}

void new_process(int nb_chp, t_process **process)
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
	i = 1;
	while (i < REG_NUMBER)
	{
		reg[i] = 0;
		i++;
	}
	reg[0] = nb_chp;
	PC = (MEM_SIZE / game->nb_players) * (nb_chp - 1);
}

void game_loop(unsigned char *arena, t_champion *champion, t_game *game)
{
	t_process *process;


}

Je cree les processus associes aux champions.

A chaque instance:
- Prendre les processus dans l'ordre.
- Le processus doit lire la prochaine commande.
- Puis executer la fonction associée.
- Le processus doit etre en stand-by jusqu'a execution de la dite fonction.
- J'execute la fonction, et je deplace le curseur.

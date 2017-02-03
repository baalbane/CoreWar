/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 15:48:50 by ttridon           #+#    #+#             */
/*   Updated: 2017/01/26 14:56:30 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "vm.h"
# include <stdio.h>

// int		main(void)
// {
// 	void *add_1;
// 	void *add_2;
//
// 	return (0);
// }

/*
Le processus a la position dans arena (i).
Il possede le registre (1er parametre).
Je dois recuperer les autres parametres dans ma arena.
*/
void	sti(t_process *process, unsigned char *arena)
{
	if (i + p1 + p2 >= MEM_SIZE)
		i = i + p1 + p2 - MEM_SIZE;
	else
		i = i + p1 + p2;
	arena[i] = r; //arena[i] est un char, je dois y mettre 4 octets soit un int;
}

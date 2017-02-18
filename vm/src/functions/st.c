/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:22:12 by ttridon           #+#    #+#             */
/*   Updated: 2017/02/18 16:54:50 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"


void	st(unsigned char *arena, t_process *process, t_champion *champion,
	 t_game *game)
{
	int		arg[MAX_ARG_NUMBER];
	int		opc;

	if (process->cooldown == -1)
	{
		process->cooldown = 5;
		return ;
	}
	opc = arena[process->PC + 1];
	process->cooldown = -1;
	if (opc && 0x192 != 0x01
		|| opc && 0x48 == 0x00
		|| opc && 0x48 == 0x10)
		return ;
	get_args(arena, PC, tab, dir_size);
	if (arg[0] > REG_NUMBER
	|| (opc && 0x48 == 0x01 && arg[1] > REG_NUMBER))
		return ;
	process->reg[arg[1]] = arg[0];
}

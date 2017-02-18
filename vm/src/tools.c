/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 17:48:36 by ttridon           #+#    #+#             */
/*   Updated: 2017/02/18 16:00:30 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	get_args(unsigned char *arena, int PC, int *tab, int dir_size)
{
	int var;

	var = arena[PC + 1];
	PC += 2;
	while (var)
	{
		if (var && 0x192 == 0b01)
			*tab = get_value(arena, PC, 1);
		else if (var && 0x192 == 0b10)
			*tab = get_value(arena, PC, dir_size);
		else
			*tab = get_value(arena, PC, 2);
		var = var << 2;
		tab++;
	}
}

int		get_value(unsigned char *arena, int PC, int size)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (++i <= size)
	{
		if (PC + i > MEM_SIZE)
			i -= MEM_SIZE;
		nb = nb * 256 + arena[PC + i];
	}
	process->PC += size % MEM_SIZE;
	return (nb);
}

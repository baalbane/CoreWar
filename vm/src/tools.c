/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 17:48:36 by ttridon           #+#    #+#             */
/*   Updated: 2017/02/20 19:37:05 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		move_PC(int PC, int size)
{
	PC = (PC + size) % MEM_SIZE;
	if (PC < 0)
		PC += MEM_SIZE;
	return (PC);
}

static int	get_ind(unsigned char *arena, int PC)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (++i <= 4)
	{
		if (PC + i > MEM_SIZE)
			PC -= MEM_SIZE;
		nb = nb * 256 + arena[PC + i];
	}
	return (nb);
}

void		get_args(unsigned char *arena, t_process *process, int *tab, int dir_size)
{
	unsigned char	var;
	int 			tmp;

	var = arena[process->PC];
	tmp = move_PC(process->PC, -1);
	process->PC = move_PC(process->PC, 1);
	while (var)
	{
		printf("var: %d\n", var);
		if (var && 0x192 == 0b01)
			*tab = get_value(arena, process, 1);
		else if (var && 0x192 == 0b10)
			*tab = get_value(arena, process, dir_size);
		else
		{
			*tab = get_value(arena, process, 2);
			*tab = get_ind(arena, *tab + tmp);
		}
		var = var << 2;
		tab++;
	}
}

int			get_value(unsigned char *arena, t_process *process, int size)
{
	int		i;
	int		nb;
	int		tmp;

	i = -1;
	nb = 0;
	tmp = process->PC;
	while (++i < size)
	{
		if (tmp + i > MEM_SIZE)
			tmp -= MEM_SIZE;
		nb = nb * 256 + arena[tmp + i];
	}
	process->PC += size % MEM_SIZE;
	return (nb);
}

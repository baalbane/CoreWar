/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 17:48:36 by ttridon           #+#    #+#             */
/*   Updated: 2017/02/24 16:30:31 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			move_PC(int PC, int size)
{
	PC = (PC + size) % MEM_SIZE;
	if (PC < 0)
		PC += MEM_SIZE;
	return (PC);
}

int			check_reg(unsigned char var, int *arg)
{
	while (var & 0xC0)
	{
		if ((var & 0xC0) == 0b01000000 && (*arg < 0 || *arg > REG_NUMBER - 1))
			return (0);
		var = var << 2;
		arg++;
	}
	return (1);
}

void 		rewrite_arena(unsigned char *arena, int PC, int value)//size?
{
	int		i;

	i = 4;
	while (--i >= 0)
	{
		arena[PC + i] = value % 256;
		value = value / 256;
	}
}

int			get_ind(unsigned char *arena, int PC)
{
	int		i;
	int		nb;

	i = -1;
	nb = 0;
	while (++i < 4)
	{
		if (PC + i > MEM_SIZE)
			PC -= MEM_SIZE;
		nb = nb * 256 + arena[PC + i];
	}
	return (nb);
}

void		get_args(unsigned char *arena, t_process *process, int *arg, int dir_size)
{
	unsigned char	var;
	int 			tmp;

	var = arena[process->PC];
	tmp = move_PC(process->PC, -1);
	process->PC = move_PC(process->PC, 1);
	while (var & 0xC0)
	{
		if ((var & 0xC0) == 0b01000000)
			*arg = get_value(arena, process, 1) - 1;
		else if ((var & 0xC0) == 0b10000000)
			*arg = get_value(arena, process, dir_size);
		else
			*arg = get_value(arena, process, 2);
		var = var << 2;
		arg++;
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

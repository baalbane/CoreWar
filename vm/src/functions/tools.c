/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 13:08:52 by ttridon           #+#    #+#             */
/*   Updated: 2017/04/05 16:28:26 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	big_to_little_endian_int(int nb)
{
	return ((nb >> 24 & 0xff) | (nb << 8 & 0xff0000)
		| (nb >> 8 & 0xff00) | (nb << 24 & 0xff000000));
}

short big_to_little_endian_short(short n)
{
	return ((n >> 8 & 0xff) | (n << 8 & 0xff00));
}

unsigned char	reverse_oct_codage(unsigned char n)
{
	return ((n >> 6 & 0b11) | (n >> 2 & 0b1100) | (n << 2 & 0b110000));
}

int		jump_params(int oct_codage, int dir_size)
{
	int		count;

	count = 1;
	while (oct_codage)
	{
		if ((oct_codage & 0b11) == REG_CODE)
			count += 1;
		else if ((oct_codage & 0b11) == DIR_CODE)
			count += dir_size;
		else
			count += IND_SIZE;
		oct_codage = oct_codage >> 2;
	}
	return (count);
}

int		if_valid_reg(int r)
{
	if (r >= 0 && r <= 15)
		return (0);
	return (1);
}

int			get_value(unsigned char *arena, int PC, int size)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (i < size)
	{
		nb = nb * 256 + arena[(PC + i) % MEM_SIZE];
		i++;
	}
	return (nb);
}

int		get_params(unsigned char *arena, int PC, int dir_size, int *tab_param)
{
	int		oct_codage;

	oct_codage = reverse_oct_codage(arena[PC]);
	PC += 1;
	while (oct_codage)
	{
		if ((oct_codage & 0b11) == REG_CODE)
		{
			if (if_valid_reg(*tab_param = ((char)get_value(arena, PC, 1) - 1)))
				return (1);
			PC += 1;
		}
		else if ((oct_codage & 0b11) == DIR_CODE)
		{
			if (dir_size == DIR_SIZE)
				*tab_param = get_value(arena, PC, 4);
			else
				*tab_param = (short)get_value(arena, PC, 2);
			PC += dir_size;
		}
		else
		{
			*tab_param = (short)get_value(arena, PC, 2);
			PC += IND_SIZE;
		}
		tab_param++;
		oct_codage = oct_codage >> 2;
	}
	return (0);
}

int		cooldown(t_process *process, int function_cooldown)
{
	if (!process->cooldown)
		process->cooldown = function_cooldown;
	process->cooldown--;
	if (!process->cooldown)
		return (0);
	return (1);
}

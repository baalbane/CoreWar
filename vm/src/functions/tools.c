/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 13:08:52 by ttridon           #+#    #+#             */
/*   Updated: 2017/04/18 18:39:02 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				big_to_little_endian_int(int nb)
{
	return ((nb >> 24 & 0xff) | (nb << 8 & 0xff0000)
		| (nb >> 8 & 0xff00) | (nb << 24 & 0xff000000));
}

unsigned char	reverse_oct_codage(unsigned char n)
{
	return ((n >> 6 & 0b11) | (n >> 2 & 0b1100) | (n << 2 & 0b110000));
}

int				jump_params(int oct_codage, int dir_size)
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

int				get_value(unsigned char *arena, int pc, int size)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (i < size)
	{
		nb = nb * 256 + arena[(pc + i) % MEM_SIZE];
		i++;
	}
	return (nb);
}

int				get_params(unsigned char *arena, int pc, int dir_size,
	int *tab_param)
{
	int		oct_codage;

	oct_codage = reverse_oct_codage(arena[pc]);
	pc += 1;
	while (oct_codage)
	{
		if ((oct_codage & 0b11) == REG_CODE && (pc += 1))
		{
			if (if_valid_reg(*tab_param = ((char)get_value(arena, pc - 1, 1)
				- 1)))
				return (1);
		}
		else if ((oct_codage & 0b11) == DIR_CODE && (pc += dir_size))
		{
			if (dir_size == DIR_SIZE)
				*tab_param = get_value(arena, pc - dir_size, 4);
			else
				*tab_param = (short)get_value(arena, pc - dir_size, 2);
		}
		else if (pc += IND_SIZE)
			*tab_param = (short)get_value(arena, pc - IND_SIZE, 2);
		tab_param++;
		oct_codage = oct_codage >> 2;
	}
	return (0);
}

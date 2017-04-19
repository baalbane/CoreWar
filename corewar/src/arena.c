/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 11:01:18 by ttridon           #+#    #+#             */
/*   Updated: 2017/04/18 20:15:20 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		write_arena(unsigned char *arena, int pc, unsigned int value,
	int size_value)
{
	pc -= 1;
	if (pc < 0)
		pc += MEM_SIZE;
	while (size_value)
	{
		arena[(pc + size_value) % MEM_SIZE] = value % 256;
		value = value / 256;
		size_value--;
	}
}

static void	put_base(int nb)
{
	char	c[3];

	c[1] = nb % 16 > 9 ? nb % 16 + 'a' - 10 : nb % 16 + '0';
	nb = nb / 16;
	c[0] = nb % 16 > 9 ? nb % 16 + 'a' - 10 : nb % 16 + '0';
	c[2] = '\0';
	ft_putstr(c);
	ft_putstr(" ");
}

void		dump_arena(unsigned char *arena)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		put_base((int)arena[i]);
		i++;
		if (i % 64 == 0)
			ft_putstr("\n");
	}
}

int			init_arena(unsigned char *arena, t_game *game)
{
	t_champion	*tmp_champion;
	int			nb_player;
	int			pos_arena;
	int			j;

	ft_bzero(arena, MEM_SIZE);
	tmp_champion = game->champion;
	nb_player = 0;
	set_champion_position(game);
	while (tmp_champion)
	{
		j = 0;
		pos_arena = tmp_champion->position;
		while (j < tmp_champion->size_code)
		{
			arena[pos_arena] = tmp_champion->code[j];
			pos_arena++;
			j++;
		}
		nb_player++;
		tmp_champion = tmp_champion->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 15:46:12 by ttridon           #+#    #+#             */
/*   Updated: 2017/01/26 18:04:51 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <unistd.h>

static int		check_flags(int ac, char **av, int *i, t_game *game)
{
	game->ncurses = 0;
	*i = 1;
	while (av[*i])
	{
		if (av[*i][0] != '-')
			break;
		if (!ft_strcmp(av[*i], "-n"))
			game->ncurses = 1;
		else
			return (1);
		ac--;
		(*i)++;
	}
	if (ac < 2 || ac > MAX_PLAYERS + 1)
		return (1);
	game->nb_players = ac - 1;
	return (0);
}

int			main(int ac, char **av)
{
	t_champion		*champion;
	t_game			*game;
	unsigned char	arena[MEM_SIZE];
	int				i;

	if (ac < 2)
		return (0);
	game = (t_game *)malloc(sizeof(t_game));
	if (check_flags(ac, av, &i, game))
		return (0);
	champion = NULL;
	while (i < ac)
	{
		parsing(av[i], &champion);
		i++;
	}
	arena_init(arena, champion, game);
	game->
	// game_loop(arena, champion, game);
	return (0);
}

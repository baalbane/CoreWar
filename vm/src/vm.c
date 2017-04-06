/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:30:34 by ttridon           #+#    #+#             */
/*   Updated: 2017/03/27 17:22:01 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	aff_winner(t_game *game)
{
	if (game->winner)
		printf("%s number %d won the game !\n",
		game->winner->name, game->winner->number);
	else
		printf("%s\n", "And the WINNER is ... I don't know.");
}

int			main(int ac, char **av)
{
	t_game			*game;
	unsigned char	arena[MEM_SIZE];

	if (ac < 2)
		return (1);
	if (!(game = (t_game *)malloc(sizeof(t_game))))
		return (1);
	if (parsing(ac, ++av, game))
		return (1);
	if (init_arena(arena, game))
		return (1);
	if (init_process(game->champion, game))
		return (1);
	if (game_loop(arena, game))
		dump_arena(arena);
	else
		aff_winner(game);
	return (0);
}

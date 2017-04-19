/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:30:34 by ttridon           #+#    #+#             */
/*   Updated: 2017/04/18 19:53:47 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	aff_winner(t_game *game)
{
	if (game->winner)
	{
		ft_putstr(game->winner->name);
		ft_putendl(" won the game !");
	}
	else
		ft_putendl("And the WINNER is ... I don't know.");
}

static void	free_struct(t_game **game)
{
	t_champion	*tmp_champion;
	t_process	*tmp_process;

	while ((*game)->champion)
	{
		ft_strdel(&(*game)->champion->name);
		ft_strdel(&(*game)->champion->comment);
		free((*game)->champion->code);
		tmp_champion = (*game)->champion;
		(*game)->champion = (*game)->champion->next;
		free(tmp_champion);
	}
	while ((*game)->process_list)
	{
		tmp_process = (*game)->process_list;
		(*game)->process_list = (*game)->process_list->next;
		free(tmp_process);
	}
	free(*game);
}

static void	clear(t_game **game, unsigned char *arena)
{
	free_struct(game);
	ft_bzero(arena, MEM_SIZE);
}

static int	error(int n)
{
	if (n == 1)
		ft_putendl("Invalid number of champions");
	else if (n == 2)
		ft_putendl("Invalid Champions");
	else if (n == 3)
		ft_putendl("Arena ERROR");
	else if (n == 4)
		ft_putendl("Process ERROR");
	return (0);
}

int			main(int ac, char **av)
{
	t_game			*game;
	unsigned char	arena[MEM_SIZE];

	if (ac < 2)
		return (error(1));
	if (!(game = (t_game *)malloc(sizeof(t_game))))
		return (0);
	game->champion = NULL;
	game->process_list = NULL;
	if (parsing(ac, ++av, game))
		return (error(2));
	if (init_arena(arena, game))
		return (error(3));
	if (init_process(game->champion, game))
		return (error(4));
	if (game_loop(arena, game))
		dump_arena(arena);
	else
		aff_winner(game);
	clear(&game, arena);
	return (0);
}

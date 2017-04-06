/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:11:11 by ttridon           #+#    #+#             */
/*   Updated: 2017/03/28 16:02:24 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	ft_isnumber(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	get_flags(int *ac, char ***av, t_game *game)
{
	if (!ft_strcmp(**av, "-dump"))
		if (--(*ac) && ++(*av) && !ft_isnumber(**av))
			game->dump = ft_atoi(**av);
		else
			return (1);
	else if (!ft_strcmp(**av, "-cursed"))
		game->ncurse = 1;
	else if (!ft_strcmp(**av, "-n"))
	{
		if (--(*ac) && ++(*av) && !ft_isnumber(**av))
		{
			if (--(*ac))
			{
				if (get_champion(*(*av + 1), ft_atoi(**av), game))
					return (1);
				(*av)++;
			}
			else
				return (1);
		}
	}
	else
		return (1);
	return (0);
}

int			parsing(int ac, char **av, t_game *game)
{
	game->champion = NULL;
	game->dump = 0;
	game->ncurse = 0;
	game->nb_players = 0;
	while (--ac)
	{
		if (*av[0] == '-')
		{
			if (get_flags(&ac, &av, game))
				return (1);
		}
		else
		{
			if (get_champion(*av, 0, game))
				return (1);
		}
		av++;
	}
	return (0);
}

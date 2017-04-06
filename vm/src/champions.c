/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:32:25 by ttridon           #+#    #+#             */
/*   Updated: 2017/03/28 16:22:53 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <unistd.h>
#include <fcntl.h>

void					set_champion_position(t_game *game)
{
	t_champion	*tmp_champion;
	int			nb_player;

	nb_player = 0;
	tmp_champion = game->champion;
	while (tmp_champion)
	{
		tmp_champion->position = (MEM_SIZE / game->nb_players) * nb_player;
		nb_player += 1;
		tmp_champion = tmp_champion->next;
	}
}

static int				set_champion_number(t_champion *champion,
	t_champion *new_champion,
	int champion_number)
{
	if (champion_number)
	{
		while (champion)
		{
			if (champion->number == champion_number)
				return (1);
			champion = champion->next;
		}
		new_champion->number = champion_number;
	}
	else
	{
		while (if_valid_number(champion, champion_number))
			champion_number++;
		new_champion->number = champion_number;
	}
	return (0);
}

static int				create_champion_bis(t_header *header,
	t_champion *new_champion)
{
	new_champion->name = ft_strdup(header->name);
	new_champion->comment = ft_strdup(header->comment);
	new_champion->size_code = big_to_little_endian_int(header->size);
	if (!(new_champion->code = ft_unstrndup(header->code,
		new_champion->size_code)))
		return (1);
	new_champion->next = NULL;
	return (0);
}

static int				create_champion(t_header *header, int champion_number,
	t_game *game)
{
	t_champion	*new_champion;
	t_champion	*tmp_champion;

	if (!(new_champion = (t_champion *)malloc(sizeof(t_champion))))
		return (1);
	if (!game->champion)
	{
		game->champion = new_champion;
		new_champion->number = champion_number;
	}
	else
	{
		if (set_champion_number(game->champion, new_champion, champion_number))
			return (1);
		tmp_champion = game->champion;
		while (tmp_champion->next)
			tmp_champion = tmp_champion->next;
		tmp_champion->next = new_champion;
	}
	if (create_champion_bis(header, new_champion))
		return (1);
	game->nb_players++;
	return (0);
}

int						get_champion(char *av, int champion_number,
	t_game *game)
{
	t_header	*header;
	int			fd;
	int			ret;

	if ((fd = open(av, O_RDONLY)) < 0)
		return (1);
	header = (t_header *)malloc(sizeof(t_header));
	if ((ret = read(fd, header, sizeof(t_header))) <= 0)
		return (1);
	close(fd);
	if (create_champion(header, champion_number, game))
	{
		free(header);
		return (1);
	}
	free(header);
	return (0);
}

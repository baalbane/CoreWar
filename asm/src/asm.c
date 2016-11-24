/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 13:56:53 by ttridon           #+#    #+#             */
/*   Updated: 2016/11/24 15:52:12 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <fcntl.h>

int		parser(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	check_name_comment(fd);
	return (1);
}

int		main(int ac, char **av)
{
	if (ac <= 1)
	{
		//message d'erreur.
		return (0);
	}
	if (!parser(av[1]))
	{
		//message d'erreur.
		return (0);
	}
	//message d'erreur.
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 13:56:53 by ttridon           #+#    #+#             */
/*   Updated: 2016/12/09 16:38:03 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <fcntl.h>

int		parser(char *file)
{
	int		fd;
	t_label	*start;

	fd = open(file, O_RDONLY);
	check_name_comment(fd);
	start = tmpname(fd);
	print_struct(start);

	t_op *optab = get_op_tab();
	print_op_tab(optab);
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

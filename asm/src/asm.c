/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 15:46:40 by baalbane          #+#    #+#             */
/*   Updated: 2017/04/18 18:58:59 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		main(int ac, char **av)
{
	if (ac <= 1)
	{
		ft_putstr("Error: No input file.\n", 2);
		return (0);
	}
	if (parser(av[1]) == -1)
	{
		ft_putstr("Error: Wrong input file.\n", 2);
	}
	return (0);
}

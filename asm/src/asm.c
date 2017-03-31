/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 15:46:40 by baalbane          #+#    #+#             */
/*   Updated: 2017/03/31 15:47:50 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		main(int ac, char **av)
{
	if (ac <= 1)
	{
		printf("Error: No input file. <--CARE PRINTF\n");
		return (0);
	}
	if (!parser(av[1]))
	{
		printf("Error: Wrong input file. <--CARE PRINTF\n");
		return (0);
	}
	return (0);
}

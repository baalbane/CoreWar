/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:17:57 by baalbane          #+#    #+#             */
/*   Updated: 2016/11/26 14:47:29 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		print_struct(t_label *start)
{
	t_function *tmp;
	printf("New label: %s\n", start->name);

	tmp = start->function;
	while (tmp != NULL)
	{
		printf("\t%s\n", tmp->line);
		tmp = tmp->next;
	}
	if (start->next)
		print_struct(start->next);
	return(1);
}

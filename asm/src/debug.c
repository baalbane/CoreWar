/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:17:57 by baalbane          #+#    #+#             */
/*   Updated: 2016/12/09 16:38:02 by baalbane         ###   ########.fr       */
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
		printf("funct:\t%s\n", tmp->line);
		tmp = tmp->next;
	}
	if (start->next)
		print_struct(start->next);
	return(1);
}

int		print_op_tab(t_op *start)
{
	printf("========================\n");
	printf("Function: %s\n", start->name);
	printf("args nbr: %d\n", start->args_number);

	printf("args type: ");
	int i = -1;
	while (++i < start->args_number)
	{
		printf("%d", start->args_type[i]);
		if (i+1 < start->args_number)
			printf(" | ");
	}
	printf("\n");

	printf("op code: %d\n", start->op_code);
	printf("cycle number: %d\n", start->cycle_number);
	printf("description: %s\n", start->description);
	printf("octet de codage: %d\n", start->octet_codage);
	printf("carry: %d\n", start->carry);
	printf("========================\n\n");

	if (start->next != NULL)
		print_op_tab(start->next);
	return(1);
}

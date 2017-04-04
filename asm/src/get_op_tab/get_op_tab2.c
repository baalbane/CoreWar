/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_tab2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:15:54 by baalbane          #+#    #+#             */
/*   Updated: 2017/04/04 16:15:57 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

t_op	*get_and(void)
{
	t_op	*new;

	new = malloc(sizeof(t_op));
	new->name = ft_strdup("and");
	new->args_number = 3;
	new->args_type[0] = 30;
	new->args_type[1] = 30;
	new->args_type[2] = 5;
	new->op_code = 6;
	new->cycle_number = 6;
	new->description = ft_strdup("et (and r1, r2, r3  r1&r2 -> r3");
	new->octet_codage = 1;
	new->label_size = 0;
	new->next = get_or();
	return (new);
}

t_op	*get_or(void)
{
	t_op	*new;

	new = malloc(sizeof(t_op));
	new->name = ft_strdup("or");
	new->args_number = 3;
	new->args_type[0] = 30;
	new->args_type[1] = 30;
	new->args_type[2] = 5;
	new->op_code = 7;
	new->cycle_number = 6;
	new->description = ft_strdup("ou (or r1, r2, r3  r1 | r2 -> r3");
	new->octet_codage = 1;
	new->label_size = 0;
	new->next = get_xor();
	return (new);
}

t_op	*get_xor(void)
{
	t_op	*new;

	new = malloc(sizeof(t_op));
	new->name = ft_strdup("xor");
	new->args_number = 3;
	new->args_type[0] = 30;
	new->args_type[1] = 30;
	new->args_type[2] = 5;
	new->op_code = 8;
	new->cycle_number = 6;
	new->description = ft_strdup("ou (xor r1, r2, r3  r1^r2 -> r3");
	new->octet_codage = 1;
	new->label_size = 0;
	new->next = get_zjmp();
	return (new);
}

t_op	*get_zjmp(void)
{
	t_op	*new;

	new = malloc(sizeof(t_op));
	new->name = ft_strdup("zjmp");
	new->args_number = 1;
	new->args_type[0] = 2;
	new->op_code = 9;
	new->cycle_number = 20;
	new->description = ft_strdup("jump if zero");
	new->octet_codage = 0;
	new->label_size = 1;
	new->next = get_ldi();
	return (new);
}

t_op	*get_ldi(void)
{
	t_op	*new;

	new = malloc(sizeof(t_op));
	new->name = ft_strdup("ldi");
	new->args_number = 3;
	new->args_type[0] = 30;
	new->args_type[1] = 10;
	new->args_type[2] = 5;
	new->op_code = 10;
	new->cycle_number = 25;
	new->description = ft_strdup("load index");
	new->octet_codage = 1;
	new->label_size = 1;
	new->next = get_sti();
	return (new);
}

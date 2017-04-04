/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_tab3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:16:00 by baalbane          #+#    #+#             */
/*   Updated: 2017/04/04 16:16:24 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

t_op	*get_sti(void)
{
	t_op	*new;

	new = malloc(sizeof(t_op));
	new->name = ft_strdup("sti");
	new->args_number = 3;
	new->args_type[0] = 5;
	new->args_type[1] = 30;
	new->args_type[2] = 10;
	new->op_code = 11;
	new->cycle_number = 25;
	new->description = ft_strdup("store index");
	new->octet_codage = 1;
	new->label_size = 1;
	new->next = get_fork();
	return (new);
}

t_op	*get_fork(void)
{
	t_op	*new;

	new = malloc(sizeof(t_op));
	new->name = ft_strdup("fork");
	new->args_number = 1;
	new->args_type[0] = 2;
	new->op_code = 12;
	new->cycle_number = 800;
	new->description = ft_strdup("fork");
	new->octet_codage = 0;
	new->label_size = 1;
	new->next = get_lld();
	return (new);
}

t_op	*get_lld(void)
{
	t_op	*new;

	new = malloc(sizeof(t_op));
	new->name = ft_strdup("lld");
	new->args_number = 2;
	new->args_type[0] = 6;
	new->args_type[1] = 5;
	new->op_code = 13;
	new->cycle_number = 10;
	new->description = ft_strdup("long load");
	new->octet_codage = 1;
	new->label_size = 0;
	new->next = get_lldi();
	return (new);
}

t_op	*get_lldi(void)
{
	t_op	*new;

	new = malloc(sizeof(t_op));
	new->name = ft_strdup("lldi");
	new->args_number = 3;
	new->args_type[0] = 30;
	new->args_type[1] = 10;
	new->args_type[2] = 5;
	new->op_code = 14;
	new->cycle_number = 50;
	new->description = ft_strdup("long load index");
	new->octet_codage = 1;
	new->label_size = 1;
	new->next = get_lfork();
	return (new);
}

t_op	*get_lfork(void)
{
	t_op	*new;

	new = malloc(sizeof(t_op));
	new->name = ft_strdup("lfork");
	new->args_number = 1;
	new->args_type[0] = 2;
	new->op_code = 15;
	new->cycle_number = 1000;
	new->description = ft_strdup("long fork");
	new->octet_codage = 0;
	new->label_size = 1;
	new->next = get_aff();
	return (new);
}

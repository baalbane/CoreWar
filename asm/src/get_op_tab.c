/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 15:20:19 by ttridon           #+#    #+#             */
/*   Updated: 2016/12/09 16:26:15 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//( , ) 1:nom; 2:nombre d'arguments; 3:type d'arguments; 4:op_code; 5:cycle;
//		6:description; 7:carry; 8:inconnu.

#include "asm.h"
/*
t_op    op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};*/
//ARGS_TYPE T_DIR:2,T_IND:3,T_REG:5

t_op	*get_op_tab()
{
	t_op	*start;

	start = malloc(sizeof(t_op));
	start->name = ft_strdup("live");
	start->args_number = 1;
	start->args_type[0] = 2;
	start->op_code = 1;
	start->cycle_number = 10;
	start->description = ft_strdup("alive");
	start->octet_codage = 0;
	start->carry = 0;
	start->next = get_ld();
	return (start);
}

t_op	*get_ld()
{
	t_op	*new;

	new = malloc(sizeof(t_op));
	new->name = ft_strdup("ld");
	new->args_number = 2;
	new->args_type[0] = 6;
	new->args_type[1] = 5;
	new->op_code = 2;
	new->cycle_number = 5;
	new->description = ft_strdup("load");
	new->octet_codage = 1;
	new->carry = 0;
	new->next = get_st();
	return (new);
}

t_op	*get_st()
{
	t_op	*new;

	new = malloc(sizeof(t_op));
	new->name = ft_strdup("st");
	new->args_number = 2;
	new->args_type[0] = 5;
	new->args_type[1] = 15;
	new->op_code = 3;
	new->cycle_number = 5;
	new->description = ft_strdup("store");
	new->octet_codage = 1;
	new->carry = 0;
	new->next = get_add();
	return (new);
}

t_op	*get_add()
{
	t_op	*new;

	new = malloc(sizeof(t_op));
	new->name = ft_strdup("add");
	new->args_number = 3;
	new->args_type[0] = 5;
	new->args_type[1] = 5;
	new->args_type[2] = 5;
	new->op_code = 4;
	new->cycle_number = 10;
	new->description = ft_strdup("addition");
	new->octet_codage = 1;
	new->carry = 0;
	new->next = get_sub();
	return (new);
}

t_op	*get_sub()
{
	t_op	*new;

	new = malloc(sizeof(t_op));
	new->name = ft_strdup("sub");
	new->args_number = 3;
	new->args_type[0] = 5;
	new->args_type[1] = 5;
	new->args_type[2] = 5;
	new->op_code = 5;
	new->cycle_number = 10;
	new->description = ft_strdup("soustraction");
	new->octet_codage = 1;
	new->carry = 0;
	new->next = get_and();
	return (new);
}

t_op	*get_and()
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
	new->carry = 0;
	new->next = get_or();
	return (new);
}

t_op	*get_or()
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
	new->carry = 0;
	new->next = get_xor();
	return (new);
}

t_op	*get_xor()
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
	new->carry = 0;
	new->next = get_zjmp();
	return (new);
}

t_op	*get_zjmp()
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
	new->carry = 1;
	new->next = get_ldi();
	return (new);
}

t_op	*get_ldi()
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
	new->carry = 1;
	new->next = get_sti();
	return (new);
}

t_op	*get_sti()
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
	new->carry = 1;
	new->next = get_fork();
	return (new);
}

t_op	*get_fork()
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
	new->carry = 1;
	new->next = get_lld();
	return (new);
}

t_op	*get_lld()
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
	new->carry = 0;
	new->next = get_lldi();
	return (new);
}

t_op	*get_lldi()
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
	new->carry = 1;
	new->next = get_lfork();
	return (new);
}

t_op	*get_lfork()
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
	new->carry = 1;
	new->next = get_aff();
	return (new);
}

t_op	*get_aff()
{
	t_op	*new;

	new = malloc(sizeof(t_op));
	new->name = ft_strdup("aff");
	new->args_number = 1;
	new->args_type[0] = 5;
	new->op_code = 16;
	new->cycle_number = 2;
	new->description = ft_strdup("aff");
	new->octet_codage = 1;
	new->carry = 0;
	new->next = NULL;
	return (new);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op_tab4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:16:30 by baalbane          #+#    #+#             */
/*   Updated: 2017/04/04 16:16:59 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

t_op	*get_aff(void)
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
	new->label_size = 0;
	new->next = NULL;
	return (new);
}

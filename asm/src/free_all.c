/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 16:59:09 by baalbane          #+#    #+#             */
/*   Updated: 2017/04/07 16:48:19 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		free_optab(t_op *optab)
{
	if (optab->next != NULL)
		free_optab(optab->next);
	free(optab->name);
	free(optab->description);
	free(optab);
	return (1);
}

int		free_label(t_label *label)
{
	if (label->next != NULL)
		free_label(label->next);
	if (label->name != NULL)
		free(label->name);
	if (label->function)
		free_function(label->function);
	free(label);
	return (1);
}

int		free_function(t_function *function)
{
	if (function->next != NULL)
		free_function(function->next);
	free(function->line);
	free(function);
	return (1);
}

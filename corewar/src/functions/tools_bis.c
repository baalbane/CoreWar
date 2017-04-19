/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 18:37:46 by ttridon           #+#    #+#             */
/*   Updated: 2017/04/18 18:39:53 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		cooldown(t_process *process, int function_cooldown)
{
	if (!process->cooldown)
		process->cooldown = function_cooldown;
	process->cooldown--;
	if (!process->cooldown)
		return (0);
	return (1);
}

int		if_valid_reg(int r)
{
	if (r >= 0 && r <= 15)
		return (0);
	return (1);
}

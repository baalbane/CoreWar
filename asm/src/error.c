/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:18:59 by ttridon           #+#    #+#             */
/*   Updated: 2016/11/24 15:52:16 by ttridon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		error_name_comment(int error_type, char *line, char *tmp)
{
	if (error_type == 1)
		ft_putendl_fd("Name already exist", 2);
	else if (error_type == 2)
		ft_putendl_fd("Comment already exist", 2);
	else if (error_type == 3)
		ft_putendl_fd("Wrong format", 2);
	ft_strdel(&line);
	ft_strdel(&tmp);
	return (0);
}

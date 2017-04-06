/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:44:07 by baalbane          #+#    #+#             */
/*   Updated: 2017/04/06 15:02:43 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	check_registre(char *line, int *i)
{
	int nb;

	nb = 0;
	(*i)++;
	while (line[*i] <= '9' && line[*i] >= '0')
	{
		nb = nb * 10 + (line[*i] - '0');
		(*i)++;
	}
	if (nb > REG_NUMBER)
		return (0);
	return (1);
}

int	check_label(char *line, int *i, t_label *label)
{
	int j;

	(*i) += 2;
	while (label != NULL)
	{
		if (label->name == NULL)
			label = label->next;
		j = 0;
		while (label->name[j] != '\0' && line[*i + j] == label->name[j])
			j++;
		if (label->name[j] == LABEL_CHAR && (line[*i + j] == ' '
		|| line[*i + j] == SEPARATOR_CHAR || line[*i + j] == '\0'))
		{
			(*i) += j;
			return (1);
		}
		label = label->next;
	}
	return (0);
}

int	check_nbr(char *line, int *i)
{
	int		j;

	(*i)++;
	j = (*i);
	if (line[*i] == '-' || line[*i] == '+')
		(*i)++;
	while (line[*i] <= '9' && line[*i] >= '0')
		(*i)++;
	if (*i == j)
		return (0);
	return (1);
}

int	check_nbr2(char *line, int *i)
{
	if (line[*i] == '-' || line[*i] == '+')
		(*i)++;
	while (line[*i] >= '0' && line[*i] <= '9')
		(*i)++;
	return (1);
}

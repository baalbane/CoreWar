/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:44:07 by baalbane          #+#    #+#             */
/*   Updated: 2016/12/18 17:15:47 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int check_registre(char *line, int *i)
{
	int nb = 0;
	(*i)++;
	while (line[*i] < '9' && line[*i] > '0')
	{
		nb = nb * 10 + line[*i];
		(*i)++;
	}
	if (nb > REG_NUMBER)
		return (0);
	return (1);
}

int check_label(char *line, int *i, t_label *label)
{
	int j;//BROKEN

	(*i) += 2;
	printf("Search LABEL: %s starting at %d, %c\n", line, *i, line[*i]);
	while (label != NULL)
	{
		printf("try LABEL: %s\n", label->name);
		j = 0;
		while (label->name[j] != '\0' && line[*i + j] == label->name[j])
			j++;
		//while(line[f] != ',' || != '\0')
		if (label->name[j] == '\0' && line[*i + j] == ' ')
			return (1);
		printf("LABEL FAIL: j: %d\n", j);
		label = label->next;
	}
	return (0);
}

int check_nbr(char *line, int *i)
{
	if (line && i)
		return (1);
	return (1);
}

int check_nbr2(char *line, int *i)
{
	if (line && i)
		return (1);
	return (1);
}

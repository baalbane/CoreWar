/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:46:06 by baalbane          #+#    #+#             */
/*   Updated: 2016/12/09 17:48:03 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	check_all_label(t_label *label, t_op *optab)
{
	t_function *tmp;

	tmp = label->function;
	while (tmp != NULL)
	{
		if (check_all_function(tmp, optab) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_all_function(t_function *function, t_op *optab)
{
	int i;
	t_op *tmp;
	if ((tmp = get_good_optab(function, optab, &i)) == NULL)
		return (0); //ERROR WRONG NAME FUNCTION
	printf("Found optabname = %s\nfor i : %d\n", tmp->name, i);
	if (check_arg(function->line, tmp, optab, &i, 0) == 0)
		return (0); //ERROR IN ARG
	return (1);
}

int	check_arg(char *line, t_op *actualop, t_op *optab, int *i, int nbrarg)
{
	while (ft_isspace(line[*i]))
		*i = *i + 1;
	if (line[*i] == 'r')
	{
		if (actualop->args_type[nbrarg] % 5 != 0
			|| check_registre(line, i) == 0)
			return (0); //WRONG REGISTRE
	}
	else if (line[*i] == '%' && line[*i + 1] == ':')
	{
		if (actualop->args_type[nbrarg] % 2 != 0
		 || check_label(line, i, optab) == 0)
			return (0);//WRONG LABEL
	}
	else if (line[*i] == '%')
	{
		if (actualop->args_type[nbrarg] % 2 != 0
		 || check_nbr(line, i) == 0)
			return (0);//WRONG NUMBER

	}
	else if (actualop->args_type[nbrarg] % 3 != 0
		|| check_nbr2(line, i) == 0)
		return (0); //WRONG NUMBER
	if (nbrarg+1 < actualop->args_number)
		return (check_arg(line, actalop, optab, i, nbrarg+1));
	return (1);
}

t_op *get_good_optab(t_function *function, t_op *optab, int *i)
{
	while (optab != NULL)
	{
		if (ft_namecmp(function->line, optab->name, i) == 1)
			return (optab);
		optab =optab->next;
	}
	return (NULL);
}

int	ft_namecmp(char *line, char *name, int *i)
{
	int j;
	j = 0;
	*i = 0;

	while (ft_isspace(line[*i]))
		*i = *i + 1;
	while (line[*i + j] == name[j])
		j++;
	*i = *i + j;
	if (name[j] == '\0' && line[*i] != 'i')
		return (1);
	return (0);
}

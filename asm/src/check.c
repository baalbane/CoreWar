/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:46:06 by baalbane          #+#    #+#             */
/*   Updated: 2016/12/18 17:03:00 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	check_all_label(t_label *label, t_op *optab, t_label *start)
{
	t_function *tmp;;
	tmp = label->function;
	while (tmp != NULL)
	{
		if (check_all_function(tmp, optab, start) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_all_function(t_function *function, t_op *optab, t_label *label)
{
	int i;
	
	if (get_good_optab(function, optab, &i) == NULL)
		return (0); //ERROR WRONG NAME FUNCTION
	if (check_arg(function, label, &i, 0) == 0)
		return (0); //ERROR IN ARG
	return (1);
}

static int	check_arg2(char *line, int *i, t_function *function, int nbrarg)
{
	if (line[*i] == 'r')
	{
		if (function->optab->args_type[nbrarg] % 5 != 0
			|| check_registre(line, i) == 0)
			return (0); //WRONG REGISTRE
		set_opcode(REG_CODE, function, nbrarg);
	}
	else if (line[*i] == DIRECT_CHAR)
	{
		if (function->optab->args_type[nbrarg] % 2 != 0
		 || check_nbr(line, i) == 0)
			return (0);//WRONG NUMBER
		set_opcode(DIR_CODE, function, nbrarg);
	}
	else
	{
		if (function->optab->args_type[nbrarg] % 3 != 0
		|| check_nbr2(line, i) == 0)
			return (0); //WRONG NUMBER
		set_opcode(IND_CODE, function, nbrarg);
	}
	return (1);
}

int	check_arg(t_function *function, t_label *label, int *i, int nbrarg)
{
	char	*line;

	line = function->line;
	if (line[*i] == ' ')
		(*i)++;
	if (nbrarg != 0 && line[(*i)++] != SEPARATOR_CHAR)
		return (0);
	if (line[*i] == ' ')
		(*i)++;
	if (line[*i] == DIRECT_CHAR && line[*i + 1] == LABEL_CHAR)
	{
		if (function->optab->args_type[nbrarg] % 2 != 0
		 || check_label(line, i, label) == 0)
			return (0);//WRONG LABEL
		set_opcode(DIR_CODE, function, nbrarg);
	}
	else if (check_arg2(line, i, function, nbrarg) == 0)
		return (0);
	if (nbrarg+1 < function->optab->args_number)
		return (check_arg(function, label, i, nbrarg+1));
	if (line[*i] != '\0')
		printf("ERROR BAKA |%c|\n", line[*i]);
	if (line[*i] == '\0')
		return (1);
	return (0);
}

t_op *get_good_optab(t_function *function, t_op *optab, int *i)
{
	while (optab != NULL)
	{
		if (ft_namecmp(function->line, optab->name, i) == 1)
		{
			function->optab = optab;
			return (optab);
		}
		optab = optab->next;
	}
	return (NULL);
}
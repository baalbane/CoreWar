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

#include "asm.h"

int	check_all_label(t_label *label, t_op *optab)
{
	t_function *tmp;
	printf("\nNew label: %s\n", label->name);
	tmp = label->function;
	while (tmp != NULL)
	{
		if (check_all_function(tmp, optab, label) == 0)
			return (0);
		tmp = tmp->next;
	}
	printf("OK!\n");
	return (1);
}

int	check_all_function(t_function *function, t_op *optab, t_label *label)
{
	int i;
	t_op *tmp;
	printf("SEARCH TAB: %s\n", function->line);
	if ((tmp = get_good_optab(function, optab, &i)) == NULL)
		return (0); //ERROR WRONG NAME FUNCTION
	printf("Found optabname = %s | for i : %d\n", tmp->name, i);
	if (check_arg(function->line, tmp, label, &i, 0) == 0)
		return (0); //ERROR IN ARG
	return (1);
}

int	check_arg(char *line, t_op *actualop, t_label *label, int *i, int nbrarg)
{
	printf("Strat check arg %d\n", nbrarg);
	while (ft_isspace(line[*i]))
		(*i)++;
	if (nbrarg != 0 && line[*i] != ',')
		return (0);
	if (line[*i] == 'r')
	{
		printf("\tcheck reg...");
		if (actualop->args_type[nbrarg] % 5 != 0
			|| check_registre(line, i) == 0)
			return (0); //WRONG REGISTRE
		printf("reg ok!\n");
	}
	else if (line[*i] == '%' && line[*i + 1] == ':')
	{
		printf("\tcheck T_DIR 1...");
		if (actualop->args_type[nbrarg] % 2 != 0
		 || check_label(line, i, label) == 0)
			return (0);//WRONG LABEL
		printf("T_DIR 1 ok!\n");
	}
	else if (line[*i] == '%')
	{
		printf("\tcheck T_DIR 2...");
		if (actualop->args_type[nbrarg] % 2 != 0
		 || check_nbr(line, i) == 0)
			return (0);//WRONG NUMBER
		printf("T_DIR 2 ok!\n");
	}
	else
	{
		printf("\tcheck T_IND ...");
		if (actualop->args_type[nbrarg] % 3 != 0
		|| check_nbr2(line, i) == 0)
			return (0); //WRONG NUMBER
		printf("T_IND ok!\n");
	}
	if (nbrarg+1 < actualop->args_number)
		return (check_arg(line, actualop, label, i, nbrarg+1));
	while (ft_isspace(line[*i]))
		*i = *i + 1;
	if (line[*i] == '\0')
		return (1);
	return (0);
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

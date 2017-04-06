/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_valid_part2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:19:52 by baalbane          #+#    #+#             */
/*   Updated: 2017/04/06 15:10:19 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_label		*read_label_function(int fd)
{
	t_label	*start;
	t_label *actu;
	char	*line;

	start = new_label(NULL, NULL);
	actu = start;
	while (get_next_line(fd, &line))
	{
		line = take_new_line(line);
		if (is_label(line))
			actu = new_label(actu, line);
		else if (line != NULL)
			new_function(actu, line);
	}
	return (start);
}

int			is_label(char *line)
{
	int i;

	i = 0;
	if (line == NULL)
		return (0);
	while (line[i] != '\0' && tmp_name_strchr(LABEL_CHARS, line[i]))
		i++;
	if (i > 0 && line[i] == ':')
		return (1);
	return (0);
}

t_label		*new_label(t_label *label, char *line)
{
	t_label	*new;

	new = malloc(sizeof(t_label));
	new->function = NULL;
	new->next = NULL;
	if (line == NULL)
		new->name = NULL;
	else
		new->name = take_label_name(new, line);
	if (label != NULL)
		label->next = new;
	return (new);
}

int			new_function(t_label *label, char *line)
{
	t_function	*function;

	function = label->function;
	while (function != NULL && function->next != NULL)
		function = function->next;
	if (function == NULL)
		label->function = new_lst_function(line);
	else
		function->next = new_lst_function(line);
	return (1);
}

t_function	*new_lst_function(char *line)
{
	t_function *new;

	new = malloc(sizeof(t_function));
	new->next = NULL;
	new->optab = NULL;
	new->line = line;
	new->ODC = 0;
	return (new);
}

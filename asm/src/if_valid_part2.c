/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_valid_part2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttridon <ttridon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 16:16:58 by ttridon           #+#    #+#             */
/*   Updated: 2016/12/09 15:19:49 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label	*tmpname(int fd)
{
	t_label	*start;
	t_label *actu;
	char	*line;

	start = new_label(NULL, NULL);
	actu = start;
	while (get_next_line(fd, &line))
	{
		if (tmp_name_strchr(line, COMMENT_CHAR))
			del_commentaire(line);
		if (is_label(line))
			actu = new_label(actu, line);
		else if (ft_isempty(line) == 0)
			new_function(actu, line);
		else
			free(line);
	}
	return (start);
}

t_label	*new_label(t_label *label, char *line)
{
	t_label	*new;
	new = malloc(sizeof(t_label));
	new->function = NULL;
	new->next = NULL;
	if (line == NULL)
		new->name = NULL;
	else
		new->name = tmp_name(new, line);
	if (label != NULL)
		label->next = new;
	return (new);
}

int		new_function(t_label *label, char *line)
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

t_function *new_lst_function(char *line)
{
	t_function *new;

	new = malloc(sizeof(t_function));
	new->next = NULL;
	new->line = line;
	return (new);
}

int		is_label(char *line)
{
	int i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	while (line[i] != '\0' && tmp_name_strchr(LABEL_CHARS, line[i]))
		i++;
	if (i > 0 && line[i] == ':')
		return (1);
	return (0);
}

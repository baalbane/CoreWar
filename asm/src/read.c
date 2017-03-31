#include "../includes/asm.h"

int		parser(char *file)
{
	int		fd;
	char	*name;
	char	*comment;
	t_label	*start;
	t_label	*tmp;
	t_op	*optab;

	if (!(fd = open(file, O_RDONLY)))
		return (0);
	printf("TOTOTOTOTO: %d\n", fd);
	if (check_name_comment(fd, &name, &comment) == 0)
	{
		printf("Error: Name or Commentaire wrong \033[41m\033[33m<--CARE PRINTF\033[0m\n");
		return (0);
	}
	start = read_label_function(fd);
	close(fd);
	optab = get_op_tab();
	tmp = start;
	while (tmp != NULL)
	{
		if (check_all_label(tmp, optab, start) == 0)
		{
			printf("FUCKING LABEL ERROR!!\n");
			return (0);
		}
		tmp = tmp->next;
	}
	write_file(start, name, comment, file);
	return (1);
}

static char	*take_new_line_bis2(char *line, char *new, int j)
{	
	if (j > 0 && new[j-1] == ' ')
		new[j-1] = '\0';
	if (new[0] == '\0')
	{
		free(new);
		new = NULL;
	}
	free(line);
	return (new);
}

static char	*take_new_line_bis(char *line, int i, int j)
{	
	char	*new;
	
	new = malloc(sizeof(char) * (j+1));
	i = 0;
	j = 0;
	while (line[i] != '\0' && line[i] != COMMENT_CHAR && line[i] != ';')
	{
		if (line[i] == '"')
		{
			new[j++] = line[i++];
			while (line[i] != '"' && line[i] != '\0')
				new[j++] = line[i++];
			if (line[i] == '"')
				new[j++] = line[i++];
		}
		while (ft_isspace(line[i]))
			i++;
		while (line[i] != '\0' && !ft_isspace(line[i]) && line[i] != COMMENT_CHAR
		&& line[i] != '"' && line[i] != ';')
			new[j++] = line[i++];
		if (ft_isspace(line[i]))
			new[j++] = ' ';		
	}
	new[j] = '\0';
	return (take_new_line_bis2(line, new, j));
}

char	*take_new_line(char *line)
{
	int 	i;
	int		j;

	i = 0;
	j = 0;
	while (line[i] != '\0' && line[i] != COMMENT_CHAR && line[i] != ';')
	{
		if (line[i] == '"')
		{
			i += 1 + 0 * j++;
			while (line[i] != '"' && line[i] != '\0')
				i += 1 + 0 * j++;
			if (line[i] == '"')
				i += 1 + 0 * j++;
		}
		while (ft_isspace(line[i]))
			i++;
		while (line[i] != '\0' && !ft_isspace(line[i]) && line[i] != COMMENT_CHAR
		&& line[i] != '"' && line[i] != ';')
			i += 1 + 0 * j++;
		if (ft_isspace(line[i]))
			j++;
	}
	return (take_new_line_bis(line, i, j));
}
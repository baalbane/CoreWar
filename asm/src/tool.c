


#incude "asm.h"

char	*tmp_name(t_label *new, char *line)
{
	char	*name;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (is_space(line[i]))
		i++;
	while (line[i+j] != ':')
		j++;
	name = malloc(sizeof(char*) * (j + 1));
	name[j] = '\0';
	while (--j >= 0)
		name[j] = line[i + j];
	tmp_name_check_fonction(new, line);
	return (name);
}

int		tmp_name_check_fonction(t_label *new, char *line)
{
	int		j;
	int		i;
	char	*function;

	i = 0;
	j = 0;
	while (line[i] != ':')
		i++;
	i++;
	while (is_space(line[i]))
		i++;
	while (line[i + j] != '\0')
		j++;
	if (j != 0)
	{
		function = malloc(sizeof(char) * (j + 1));
		function[j] = '\0';
		while (--j >= 0)
			function[j] = line[i + j];
		new_function(new, function);
	}
	free (line);
	return (1);
}

int		tmp_name_strchr(char *line, char a)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != a)
		i++;
	if (line[i] == a)
		return (1);
	return (0);
}

int		del_commentaire(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '#')
		i++;
	while (line[i+1] != '\0')
		line[i++] = '\0';
	return (1);
}

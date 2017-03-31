#include "../includes/asm.h"

int		check_name_comment(int fd, char **name_str, char **comment_str)
{
	char		*line;
	static	int	name = 0;
	static	int	comment = 0;

	while ((name == 0 || comment == 0) && get_next_line(fd, &line))
	{
		line = take_new_line(line);
		if (line != NULL && check_format(line, NAME_CMD_STRING, PROG_NAME_LENGTH))
		{
			if (name != 0)
				return (0);
			name = 1;
			*name_str = line;
		}
		else if (line != NULL && check_format(line, COMMENT_CMD_STRING, COMMENT_LENGTH))
		{
			if (comment != 0)
				return (0);
			comment = 1;
			*comment_str = line;
		}
		else if (line != NULL)
		{
			free(line);
			return (0);
		}
	}
	return (1);
}

int		check_format(char *line, char *str, int len)
{
	int		i;
	int		j;
	
	i = 0;
	while (line[i] != '\0' && str[i] != '\0' && line[i] == str[i])
		i++;
	if (str[i] != '\0')
		return (0);
	if (line[i] != ' ' || line[i+1] != '"')
	{
		printf("Error: No name after \".name\". \033[41m\033[33m<--CARE PRINTF\033[0m\n");
		return (0);
	}
	i+=2;
	j = 0;
	while (line[i+j] != '\0' && line[i+j] != '"')
		j++;
	if (line[i+j] != '"' || line[i+j+1] != '\0' || j-1 > len)
		return (0);
	
	
	return (1);
}

int		set_opcode(int type, t_function *function, int nbrarg)
{
	if (nbrarg == 0)
		function->ODC += type * 64;
	else if (nbrarg == 1)
		function->ODC += type * 16;
	else if (nbrarg == 2)
		function->ODC += type * 4;
	else
		function->ODC += type;
	return (1);
}

#include "../includes/asm.h"

int		set_pos(t_label *start, int pos)
{
	t_function *tmp;
	
	while (start != NULL)
	{
		start->pos = pos;
		tmp = start->function;
		while (tmp != NULL)
		{
			tmp->pos = pos;
			pos += add_pos(tmp);
			tmp = tmp->next;
		}
		start = start->next;
	}
	return (pos);
}

int	add_pos(t_function *function)
{
	int				i;
	unsigned char	var;
	
	var = (unsigned char)function->ODC;
	i = 1;
	if (function->optab->octet_codage == 1)
		i++;
	while (var & 0xC0)
	{
		if ((var & 0xC0) == 0b01000000)
			i += 1;
		else if ((var & 0xC0) == 0b10000000)
			i += function->optab->label_size == 0 ? 4 : 2;
		else
			i += 2;
		var = var << 2;
	}
	return (i);
}
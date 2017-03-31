
#include "../../includes/asm.h"

t_op	*get_aff()
{
	t_op	*new;

	new = malloc(sizeof(t_op));
	new->name = ft_strdup("aff");
	new->args_number = 1;
	new->args_type[0] = 5;
	new->op_code = 16;
	new->cycle_number = 2;
	new->description = ft_strdup("aff");
	new->octet_codage = 1;
	new->label_size = 0;
	new->next = NULL;
	return (new);
}


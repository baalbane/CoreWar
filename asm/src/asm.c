#include "../includes/asm.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
	if (ac <= 1)
	{
		printf("Error: No input file. \033[41m\033[33m<--CARE PRINTF\033[0m\n");
		//message d'erreur.
		return (0);
	}
	if (!parser(av[1]))
	{
		printf("Error: Wrong input file. \033[41m\033[33m<--CARE PRINTF\033[0m\n");
		return (0);
	}
	//message d'erreur?
	return (0);
}

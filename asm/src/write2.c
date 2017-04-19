/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baalbane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 16:35:55 by baalbane          #+#    #+#             */
/*   Updated: 2017/04/07 17:14:18 by baalbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		write_reg(int fd, char *str, int *i)
{
	unsigned char	a[1];

	(*i)++;
	a[0] = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
		a[0] = a[0] * 10 + str[(*i)++] - '0';
	write(fd, a, 1);
	return (1);
}

int		write_dir(int fd, t_function *function, int *i)
{
	unsigned int	nb;
	int				size;
	int				neg;

	(*i) += 1;
	neg = 0;
	if (function->line[*i] == '-')
	{
		neg = 1;
		(*i) += 1;
	}
	size = 2;
	if (function->optab->label_size == 0)
		size = 4;
	nb = 0;
	while (function->line[*i] >= '0' && function->line[*i] <= '9')
		nb = (nb * 10 + function->line[(*i)++] - '0');
	if (neg == 0)
		write_nb(nb, fd, size);
	else
		write_nb(0 - nb, fd, size);
	return (1);
}

int		write_dir_label(int fd, t_function *function, int *i, t_label *start)
{
	unsigned int	len;
	int				size;

	(*i) += 2;
	len = take_pos_label(start, function->line, i) - function->pos;
	size = 2;
	if (function->optab->label_size == 0)
		size = 4;
	write_nb(len, fd, size);
	return (1);
}

int		write_nb(unsigned int nb, int fd, int size)
{
	unsigned char	a[4];
	int				i;

	i = size;
	while (--i >= 0)
	{
		a[i] = nb % 256;
		nb = nb / 256;
	}
	write(fd, a, size);
	return (1);
}

int		write_ind(int fd, char *str, int *i)
{
	unsigned short	nb;
	int				neg;

	neg = 0;
	if (str[*i] == '-')
	{
		neg = 1;
		(*i) += 1;
	}
	nb = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
		nb = (unsigned short)(nb * 10 + str[(*i)++] - '0');
	if (neg)
		nb = -nb;
	write_nb((unsigned int)nb, fd, 2);
	return (1);
}

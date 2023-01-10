/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cust.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:42:41 by aurel             #+#    #+#             */
/*   Updated: 2022/11/24 19:08:01 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_int(long long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_putstr_cust(const char *s, int fd)
{
	int	count;

	count = 0;
	if (!s)
	{
		count = 6;
		write(fd, "(null)", 6);
	}
	else
	{
		while (s[count])
		{
			write(fd, &s[count], 1);
			count++;
		}
	}
	return (count);
}

int	ft_putchar_cust(unsigned char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	ft_putnbr_cust(int n, int fd)
{
	char			c;
	long long int	nb_u;
	int				len;

	c = '0';
	nb_u = n;
	len = 0;
	if (nb_u < 0)
	{
		nb_u = nb_u * -1;
		write(fd, "-", 1);
		len++;
	}
	if (nb_u >= 10)
	{
		ft_putnbr_cust(nb_u / 10, fd);
	}
	c = '0' + (nb_u % 10);
	write(fd, &c, 1);
	return (ft_strlen_int(n) + len);
}

int	ft_putnbr_unsigned(unsigned int n, int fd)
{
	char			c;
	int				len;

	c = '0';
	len = ft_ustrlen_int(n);
	if (n >= 10)
		ft_putnbr_unsigned(n / 10, fd);
	c = '0' + (n % 10);
	write(fd, &c, 1);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:46:55 by aucaland          #+#    #+#             */
/*   Updated: 2022/11/11 16:35:53 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	nb_u;

	c = '0';
	if (n < 0)
	{
		nb_u = n * -1;
		write(fd, "-", 1);
	}
	else
		nb_u = n;
	if (nb_u >= 10)
	{
		ft_putnbr_fd(nb_u / 10, fd);
	}
	c = '0' + (nb_u % 10);
	write(fd, &c, 1);
}

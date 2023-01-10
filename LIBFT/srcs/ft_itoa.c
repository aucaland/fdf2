/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 23:55:47 by aurel             #+#    #+#             */
/*   Updated: 2022/11/12 23:50:58 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_nbr(long long int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*str;
	long long int	nbr;
	int				size;

	nbr = n;
	size = count_nbr(nbr);
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	str[size--] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	else if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[size--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 09:29:04 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/02 09:35:05 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_allowed(char *base)
{
	int	nbr_base;
	int	i;

	i = 1;
	nbr_base = 0;
	while (base[nbr_base])
	{
		if (base[nbr_base] == '+' || base[nbr_base] == '-')
			return (0);
		while (base[nbr_base + i])
		{
			if (base[nbr_base] == base[nbr_base + i])
			{
				return (0);
			}
			i++;
		}
		i = 1;
		nbr_base++;
	}
	if (nbr_base == 0 || nbr_base == 1)
		return (0);
	return (1);
}

static int	long long	find_index_str(char str, char *base)
{
	long long int	i;
	int				j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (str == base[i])
		{
			if (str == 0)
				return (-10000);
			else
				return (i);
		}
		i++;
	}
	return (-1);
}

long long int	ft_pow_long(long long int nbr_base, int p)
{
	if (p != 0)
		return (ft_pow_long(nbr_base, p - 1) * (nbr_base));
	else
		return (1);
}

static long long int	convert_in_dec(long long int nbr_base \
		, char *base, char *str, int i)
{
	long long int	value;
	int				sign;
	int				p;

	value = 0;
	sign = 1;
	p = 0;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = sign * -1;
	}
	if (find_index_str(str[i], base) == -1 && \
			find_index_str(str[i], base) != -10000)
		return (0);
	while (str[i + p] && find_index_str(str[i + p], base) != -1)
		p++;
	p--;
	while (p >= 0)
	{
		value += find_index_str(str[i], base) * ft_pow_long(nbr_base, p);
		i++;
		p--;
	}
	return (value * sign);
}

long long int	ft_atoi_base(char *str, char *base)
{
	int				i;
	long long int	nbr_base;

	i = 0;
	nbr_base = 0;
	if (!is_allowed(base))
		return (0);
	while (base[nbr_base])
		nbr_base++;
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' \
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
			i++;
		break ;
	}
	return (convert_in_dec(nbr_base, base, str, i));
}

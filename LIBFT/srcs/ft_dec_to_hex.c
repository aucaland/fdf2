/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:33:27 by aurel             #+#    #+#             */
/*   Updated: 2022/11/24 19:03:49 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_pow(int nbr_base, int p)
{
	if (p != 0)
		return (ft_pow(nbr_base, p - 1) * (nbr_base));
	else
		return (1);
}

char	*ft_create_str(int final_size)
{
	char	*tab;

	tab = malloc(sizeof(char) * (final_size));
	if (!tab)
		return (0);
	tab[final_size - 1] = '\0';
	return (tab);
}

int	count_len(size_t nb, int nbr_base)
{
	int	len_final;

	len_final = 0;
	while ((ft_pow(nbr_base, len_final)) <= (nb))
	{
		if (ft_pow(nbr_base, len_final++) == 0)
		{
			len_final--;
			break ;
		}
	}
	return (len_final);
}

int	ft_put_itoa_hex(size_t nb, char *base_hex)
{
	int				i;
	char			*str;
	int				len_final;
	int				nbr_base;

	nbr_base = ft_strlen(base_hex);
	len_final = count_len(nb, nbr_base);
	if (len_final == 0)
		return (ft_putstr_cust("0x0", 1));
	i = len_final - 1;
	str = ft_create_str(len_final + 1);
	if (!str)
		return (-1);
	write(1, "0x", 2);
	while (nb > 0)
	{
		str[i--] = base_hex[nb % nbr_base];
		nb = nb / nbr_base;
	}
	while (str[++i])
		ft_putchar_cust(str[i], 1);
	free(str);
	return (len_final + 2);
}

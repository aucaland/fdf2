/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_udec_to_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:49:56 by aurel             #+#    #+#             */
/*   Updated: 2022/11/25 12:33:41 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_put_uitoa_hex(unsigned int nb, char *base_hex)
{
	int				i;
	char			*str;
	int				len_final;
	int				nbr_base;

	nbr_base = ft_strlen(base_hex);
	len_final = count_len(nb, nbr_base);
	if (nb == 0)
		return (ft_putchar_cust('0', 1));
	i = len_final - 1;
	str = ft_create_str(len_final + 1);
	if (!str)
		return (-1);
	while (nb > 0)
	{
		str[i--] = base_hex[nb % nbr_base];
		nb = nb / nbr_base;
	}
	while (str[++i])
		ft_putchar_cust(str[i], 1);
	free(str);
	return (len_final);
}

int	ft_ustrlen_int(unsigned int n)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:09:41 by aurel             #+#    #+#             */
/*   Updated: 2022/12/04 20:46:47 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*entry_zero(char *base_to)
{
	char	*result_zero;

	result_zero = ft_create_str(2);
	result_zero[0] = base_to[0];
	result_zero[1] = '\0';
	return (result_zero);
}

char	*ft_itoa_base(long long int nb, char *base_to)
{
	int				i;
	long long int	nbr_base;
	size_t			nb_un;
	char			*str;
	int				len_final;

	nbr_base = ft_strlen(base_to);
	len_final = 0;
	nb_un = nb;
	if (nb < 0)
		nb_un = -nb;
	while ((ft_pow(ft_strlen(base_to), len_final)) <= (nb_un))
		len_final++;
	if (nb < 0)
		len_final++;
	i = len_final - 1;
	str = ft_create_str(len_final + 1);
	while (nb_un > 0)
	{
		str[i--] = base_to[nb_un % nbr_base];
		nb_un = nb_un / nbr_base;
	}
	if (nb < 0)
		str[0] = '-';
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char			*result;
	long long int	nb;

	if (!is_allowed(base_to) || !is_allowed(base_from))
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	if (nb == 0)
	{
		return (entry_zero(base_to));
	}
	result = ft_itoa_base(nb, base_to);
	return (result);
}

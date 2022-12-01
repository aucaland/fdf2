/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:12:28 by aurel             #+#    #+#             */
/*   Updated: 2022/11/28 18:47:48 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_which_format(const char format, va_list ap)
{
	int	ret;

	ret = 0;
	if (format == 'c')
		ret += ft_putchar_cust(va_arg(ap, int), 1);
	else if (format == 's')
		ret += ft_putstr_cust(va_arg(ap, const char *), 1);
	else if (format == 'p')
		ret += ft_put_itoa_hex(va_arg(ap, size_t), "0123456789abcdef");
	else if ((format == 'd' || format == 'i'))
		ret += ft_putnbr_cust(va_arg(ap, int), 1);
	else if (format == 'u')
		ret += ft_putnbr_unsigned(va_arg(ap, unsigned int), 1);
	else if (format == 'x')
		ret += ft_put_uitoa_hex(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (format == 'X')
		ret += ft_put_uitoa_hex(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (format == '%')
		ret += ft_putchar_cust('%', 1);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;
	int		total;
	int		i;

	i = 0;
	ret = 0;
	total = 0;
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
			ret = ft_which_format(format[++i], ap);
		else if (format[i] != '%')
			ret = ft_putchar_cust(format[i], 1);
		if (ret == -1)
			return (-1);
		total += ret;
		i++;
	}
	va_end(ap);
	return (total);
}

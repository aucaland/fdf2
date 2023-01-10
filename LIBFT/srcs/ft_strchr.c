/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:27:48 by aucaland          #+#    #+#             */
/*   Updated: 2022/11/09 18:19:05 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str_cast;
	char	chr_cast;

	str_cast = (char *)s;
	chr_cast = (char)c;
	while (*str_cast && *str_cast != chr_cast)
		str_cast++;
	if (*str_cast == chr_cast)
		return ((char *)str_cast);
	return (NULL);
}

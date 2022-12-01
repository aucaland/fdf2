/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:48:15 by aucaland          #+#    #+#             */
/*   Updated: 2022/11/22 16:43:54 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	char	*str_cast;
	int		i;

	str_cast = (char *)s;
	i = 0;
	if (start >= ft_strlen(str_cast) || !s)
		len = 0;
	else if (len > ft_strlen(&str_cast[start]))
		len = ft_strlen(&str_cast[start]);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (start <= ft_strlen(str_cast) && str_cast[start] && len > 0)
	{
		dst[i++] = str_cast[start++];
		len--;
	}
	dst[i] = '\0';
	return (dst);
}

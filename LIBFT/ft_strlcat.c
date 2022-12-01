/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:25:02 by aucaland          #+#    #+#             */
/*   Updated: 2022/11/15 17:10:24 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len;

	if (dstsize != 0)
		len = ft_strlen(dst);
	else
		return (ft_strlen(src));
	if (len >= dstsize)
		return (dstsize + ft_strlen(src));
	i = len;
	j = 0;
	while ((src[j]) && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	len = len + ft_strlen(src);
	return (len);
}

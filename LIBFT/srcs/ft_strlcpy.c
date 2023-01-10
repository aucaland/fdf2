/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:14:12 by aucaland          #+#    #+#             */
/*   Updated: 2022/11/12 11:42:54 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len_src_c;
	size_t	i;

	len_src = 0;
	i = 0;
	while (src[len_src])
		len_src++;
	len_src_c = len_src;
	if (dstsize)
	{
		while (len_src > 0 && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
			len_src--;
		}
		dst[i] = '\0';
	}
	return (len_src_c);
}

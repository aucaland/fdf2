/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:00:09 by aucaland          #+#    #+#             */
/*   Updated: 2022/11/12 18:51:12 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*un_src;
	char	*un_dst;
	size_t	i;

	i = 0;
	un_src = (char *)src;
	un_dst = (char *)dst;
	if (src < dst)
	{
		while (len > 0)
		{
			(*(un_dst + len - 1)) = *(un_src + len - 1);
			len--;
		}
	}
	else if (dst < src)
	{
		while (i < len)
		{
			*(un_dst + i) = *(un_src + i);
			i++;
		}
	}
	return (dst);
}

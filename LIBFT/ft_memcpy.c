/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:56:22 by aucaland          #+#    #+#             */
/*   Updated: 2022/11/11 18:17:47 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*cpy_dest;
	char	*cpy_src;

	if (src == NULL && dest == NULL && n > 0)
	{
		return (dest);
	}
	cpy_dest = (char *) dest;
	cpy_src = (char *) src;
	while (n > 0)
	{
		*cpy_dest = *cpy_src;
		n--;
		cpy_dest++;
		cpy_src++;
	}
	return (dest);
}

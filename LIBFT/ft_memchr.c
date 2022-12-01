/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:52:19 by aucaland          #+#    #+#             */
/*   Updated: 2022/11/12 18:18:40 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	u_c;
	unsigned char	*u_s;

	u_c = (unsigned char)c;
	u_s = (unsigned char *)s;
	while (n > 0)
	{
		if (*u_s == u_c)
			return (u_s);
		u_s++;
		n--;
	}
	return (NULL);
}

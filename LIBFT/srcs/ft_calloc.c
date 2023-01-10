/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:36:24 by aucaland          #+#    #+#             */
/*   Updated: 2022/11/14 10:38:07 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	tot;

	if (size && count > SIZE_MAX / size)
		return (0);
	tot = size * count;
	ptr = malloc(sizeof(char) * tot);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, tot);
	return (ptr);
}

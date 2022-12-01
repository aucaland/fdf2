/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:31:59 by aucaland          #+#    #+#             */
/*   Updated: 2022/11/12 11:23:43 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*a;
	char	c_c;

	c_c = (char)c;
	a = (char *)s;
	i = 0;
	while (*a)
	{
		a++;
		i++;
	}
	while (*a != c_c && i > 0)
	{
		a--;
		i--;
	}
	if (*a == c_c)
		return (a);
	return (NULL);
}

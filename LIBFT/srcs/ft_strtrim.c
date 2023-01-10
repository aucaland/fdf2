/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:54:15 by aucaland          #+#    #+#             */
/*   Updated: 2022/11/13 17:57:02 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	charset_contain(const char s1, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len_s1;
	size_t	i;
	char	*dst;

	if (!s1)
		return (NULL);
	len_s1 = ft_strlen(s1);
	i = 0;
	while (s1[i])
	{
		if (charset_contain(s1[i], set))
			i++;
		else
			break ;
	}
	while (len_s1 > i)
	{
		if (charset_contain(s1[len_s1 - 1], set))
			len_s1--;
		else
			break ;
	}
	dst = ft_substr(s1, i, len_s1 - i);
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:27:20 by aucaland          #+#    #+#             */
/*   Updated: 2022/11/15 16:13:33 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	contain_charset(char *h, char *n, size_t len_needle, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (h[j] && n[i] && len-- > 0)
	{
		if (h[j] == n[i])
		{
			j++;
			i++;
		}
		else
			break ;
	}
	if (i == len_needle)
		return (1);
	return (0);
}

static char	*ft_compare(char *h, char *n, size_t len_needle, size_t len)
{
	size_t	len_h;

	len_h = ft_strlen(h);
	while (len_h > 0 && len > 0)
	{
		if (contain_charset(h, n, len_needle, len))
			return (h);
		h++;
		len--;
		len_h--;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;
	size_t	len_needle;

	n = (char *)needle;
	if (*needle == '\0')
		return ((char *)haystack);
	len_needle = ft_strlen(needle);
	if (len == 0 || (*haystack == '\0' && *n != '\0'))
		return (0);
	h = (char *)haystack;
	return (ft_compare(h, n, len_needle, len));
}

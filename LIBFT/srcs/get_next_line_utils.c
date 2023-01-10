/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:22:53 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/02 11:39:03 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr_gnl(char *s, int c)
{
	char	*str_cast;
	char	chr_cast;

	str_cast = (char *)s;
	chr_cast = (char)c;
	while (*str_cast && *str_cast != chr_cast)
		str_cast++;
	if (*str_cast == chr_cast)
		return ((char *)str_cast);
	return (NULL);
}

void	*ft_calloc_gnl(size_t count, size_t size)
{
	void	*ptr;
	size_t	tot;
	size_t	i;

	i = 0;
	if (size && count > SIZE_MAX / size)
		return (0);
	tot = size * count;
	ptr = malloc(sizeof(char) * tot);
	if (!ptr)
		return (NULL);
	while (i < tot)
	{
		*(unsigned char *)ptr = 0;
		i++;
		ptr++;
	}
	return (ptr - i);
}

char	*ft_substr_gnl(char *str, unsigned int start, size_t len)
{
	char		*dst;
	size_t		i;

	i = 0;
	if (!str || start >= ft_strlen_gnl(str))
		len = 0;
	else if (len > ft_strlen_gnl(&str[start]))
		len = ft_strlen_gnl(&str[start]);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (start <= ft_strlen_gnl(str) && str[start] && len > 0)
	{
		dst[i++] = str[start++];
		len--;
	}
	dst[i] = '\0';
	return (dst);
}

static void	fill_dst(char *dst, char *s1, char *s2)
{
	int	len_s1;
	int	len_s2;

	len_s2 = 0;
	len_s1 = 0;
	while (s1 && s1[len_s1])
	{
		dst[len_s1] = s1[len_s1];
		len_s1++;
	}
	while (s2 && s2[len_s2])
	{
		dst[len_s1] = s2[len_s2];
		len_s2++;
		len_s1++;
	}
	dst[len_s1] = '\0';
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*dst;
	int		len_s1;
	int		len_s2;

	len_s1 = 0;
	len_s2 = 0;
	while (s1 && s1[len_s1])
		len_s1++;
	while (s2 && s2[len_s2])
		len_s2++;
	dst = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!dst)
		return (NULL);
	fill_dst(dst, s1, s2);
	free(s1);
	s1 = NULL;
	return (dst);
}

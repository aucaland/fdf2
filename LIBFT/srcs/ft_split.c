/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:25:48 by aurel             #+#    #+#             */
/*   Updated: 2022/11/22 18:32:51 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contain_char(char c, char const s)
{
	if (s == c)
		return (1);
	return (0);
}

static char	**free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**ft_count_and_fill(char **tab, const char *s, size_t count, char c)
{
	unsigned int	i;
	size_t			nbr_letter;
	size_t			word_number;

	word_number = 0;
	i = 0;
	while (s[i] && word_number < count)
	{
		nbr_letter = 0;
		while (s[i] && contain_char(c, s[i]))
			i++;
		while (s[i] && !contain_char(c, s[i]))
		{
			nbr_letter++;
			i++;
		}
		tab[word_number++] = ft_substr(s, i - nbr_letter, nbr_letter);
		if (!tab[word_number - 1])
			return (free_tab(tab));
	}
	return (tab);
}

static int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	if (!c)
		return (1);
	i = 0;
	count = 0;
	while (s[i] && contain_char(c, s[i]))
		i++;
	while (s[i])
	{
		while (s[i] && !(contain_char(c, s[i])))
			i++;
		count += 1;
		while (s[i] && (contain_char(c, s[i])))
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	size_t			count;

	if (s == NULL)
		return (NULL);
	else
		count = count_word(s, c) + 1;
	tab = ft_calloc(count, sizeof(char *));
	if (!tab)
		return (NULL);
	return (ft_count_and_fill(tab, s, count - 1, c));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:13:28 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/02 00:28:44 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../LIBFT/libft.h"
#include "../fdf.h"

int	is_space(char str)
{
	if (str == '\t' || str == '\n' || str == '\v' \
		|| str == '\f' || str == '\r' || str == ' ')
		return (1);
	return (0);
}

int count_word(t_list *content)
{
	int i;
	int nbr_word;
	int comp;

	i = 0;
	nbr_word = 0;
	while (t_list->content[i])
	{
		comp = 0;
		while (t_list->content[i] && is_space(t_list->content[i]))
			i++;
		while (t_list->content[i] && !is_space(t_list->content[i]) && t_list->content[i])
		{
			i++;
			comp++;
		}
		if (comp > 0)
			nbr_word++;
	}
	return (nbr_word);
}

int get_list(t_list list_pars, int fd)
{
	t_list *top;
	char *str;
	int count_line;

	count_line = 0;
	list_pars = ft_lstnew(get_next_line(fd));
	top = list_pars;
	while ((str = get_next_line(fd)))
	{
		ft_lstadd_back(&list_pars, ft_lstnew(str));
		count_line++;
		free(str);
	}
	list_pars = top;
	return (count_line);
}

int *parsing(int fd)
{
	t_list list_pars;
	int nbr_line;
	int nbr_word;
	int **tab;

	nbr_line = get_list(list_pars, fd);
	nbr_word = count_word(list_pars);
	tab = malloc(sizeof(int *) * nbr_line);
	*tab = malloc(sizeof(int) * nbr_word);


}
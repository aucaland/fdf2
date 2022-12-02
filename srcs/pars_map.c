/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:13:28 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/02 10:26:47 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>
int	is_space(char str)
{
	if (str == '\t' || str == '\n' || str == '\v' \
		|| str == '\f' || str == '\r' || str == ' ')
		return (1);
	return (0);
}

//int	count_word(t_list **list)
//{
//	int	i;
//	int	nbr_word;
//	int	comp;
//
//	i = 0;
//	nbr_word = 0;
//	while ((*list->content)[i])
//	{
//		comp = 0;
//		while (list->content[i] && is_space(t_list->content[i]))
//			i++;
//		while (list->content[i] && !is_space(list->content[i]) && list->content[i])
//		{
//			i++;
//			comp++;
//		}
//		if (comp > 0)
//			nbr_word++;
//	}
//	return (nbr_word);
//}

int	get_list(t_list *list_pars, int fd)
{
	t_list	*top;
	char	*str;
	int		count_line;

	count_line = 0;
	list_pars = ft_lstnew(get_next_line(fd));
	top = list_pars;
	str = get_next_line(fd);
//	dprintf(1, "%s", str);
	while (str)
	{
		ft_lstadd_back(&list_pars, ft_lstnew(str));
		count_line++;
		free(str);
		str = get_next_line(fd);
	}
	list_pars = top;
	return (count_line);
}

int	**parsing(int fd)
{
	t_list	*list_pars;
	int		nbr_line;
	int		nbr_word;
	int		**tab;

	printf("%d", fd);
	printf("%s", get_next_line(fd));
	nbr_line = get_list(list_pars, fd);
//	dprintf(1, "%d", nbr_line);
//	nbr_word = count_word(list_pars);
//	tab = malloc(sizeof(int *) * nbr_line);
//	*tab = malloc(sizeof(int) * nbr_word);
	return (1);
}

int main()
{
	int fd = open("../test_maps/10-2.fdf", O_RDONLY);
	*parsing(fd);
	close(fd);
}
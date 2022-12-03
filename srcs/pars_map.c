/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:13:28 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/03 12:53:33 by aurel            ###   ########.fr       */
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

int	count_word(t_list *list)
{
	int	i;
	int	nbr_word;
	int	comp;
	char *list_content;

	i = 0;
	nbr_word = 0;
	list_content = list->content;
	while ((list_content)[i])
	{
		comp = 0;
		while (list_content[i] && is_space(list_content[i]))
			i++;
		while (list_content[i] && !is_space(list_content[i]) && list_content[i])
		{
			i++;
			comp++;
		}
		if (comp > 0)
			nbr_word++;
	}
	return (nbr_word);
}

int	get_list(t_list **list_pars, int fd)
{
	char	*str;
	int		count_line;

	count_line = 0;
	str = get_next_line(fd);
	*list_pars = NULL;
	while (str != NULL)
	{
		ft_lstadd_back(list_pars, ft_lstnew(ft_strdup(str)));
		free(str);
		count_line++;
		str = get_next_line(fd);
	}
	return (count_line);
}

void	fill_tab(t_list *list_pars, t_fdf *fdf, int nbr_line, int nbr_word)
{
	t_list	*top;
	char	*list_content;
	int		i;
	int		j;

	i = 0;
	top = list_pars;
//	dprintf(1, "size=[%d;%d]\n", nbr_line, nbr_word);
	while (i < nbr_line)
	{
		list_content = list_pars->content;
	//	dprintf(1, "i=%d - %s\n", i, list_content);
		fdf->map->tab[i] = malloc(sizeof(int) * nbr_word);
		j = 0;
		while (j < nbr_word)
		{
		//	dprintf(1, "tab[%d;%d]\n", i, j);
			while (is_space(*list_content))
				list_content++;
			fdf->map->tab[i][j] = ft_atoi_base((list_content), "0123456789");

			while (!is_space(*list_content))
				list_content++;
			j++;
		}
		list_pars = list_pars->next;
		i++;
	}
	ft_lstclear(&top, &free);
}

t_fdf *init_struct(int nbr_line)//TODO: init all struct
{
	t_fdf *fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (free(fdf), fdf = NULL, NULL);
	fdf->map = malloc(sizeof(t_map));
	if (!(fdf->map))
		return (ft_free(fdf->map, sizeof(t_map)), NULL);
	fdf->map->tab = malloc(sizeof(int *) * nbr_line);
	if (!(fdf->map->tab))
		return (ft_free(fdf->map, sizeof(t_map)), ft_free(fdf, sizeof(t_fdf)), NULL);
	return (fdf);
}

t_fdf	*parsing(int fd)
{
	t_list	*list_pars;
	t_fdf	*fdf;
//	char	*list_content;
	int		nbr_line;
	int		nbr_word;

	nbr_line = get_list(&list_pars, fd);
	if (nbr_line <= 0)
		return (NULL);
//	list_content = list_pars->content;
//	dprintf(1, "%d", nbr_line);
	nbr_word = count_word(list_pars);
	fdf = init_struct(nbr_line);
//	dprintf(1, "%s", list_pars->content);
//	dprintf(1, "%d", nbr_word);
	fill_tab(list_pars, fdf, nbr_line, nbr_word);
	return (fdf);
}

int	main()
{
	int fd = open("../test_maps/mars.fdf", O_RDONLY);
	*parsing(fd);
	close(fd);
}
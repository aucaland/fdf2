/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:13:28 by aucaland          #+#    #+#             */
/*   Updated: 2023/01/30 10:13:14 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	count_word(t_fdf *fdf, t_list *list)
{
	int		i;
	int		comp;
	char	*content;
	int		count;
	int		nbr_word;

	count = 0;
	while (list != NULL)
	{
		i = 0;
		content = list->content;
		nbr_word = 0;
		while (content[i])
		{
			comp = 0;
			while (content[i] && ft_isspace(content[i]))
				i++;
			while (content[i] && !ft_isspace(content[i++]))
				comp++;
			if (comp > 0)
				nbr_word++;
		}
		list = list->next;
		check_map(fdf, nbr_word, ++count);
	}
}

static int	read_file(t_list **list_pars, t_fdf *fdf, int fd)
{
	char	*line;
	t_list	*new;
	int		count_line;

	count_line = 0;
	new = NULL;
	line = get_next_line(fd);
	if (!line)
		close(fd);
	protect_alloc(fdf, (char *)line, NULL, "for 'line' or empty map");
	while (line != NULL)
	{
		new = ft_lstnew(line);
		if (new == NULL)
		{
			free(line);
			close(fd);
			protect_alloc_list(fdf, (t_list *)new, (void **)list_pars, "newl");
		}
		ft_lstadd_back(list_pars, new);
		count_line++;
		line = get_next_line(fd);
	}
	fdf->map->nbr_line = count_line;
	return (count_line);
}

static int	fill_tab(t_list *list_pars, t_fdf *fdf, int nbr_line, int nbr_word)
{
	char	*list_content;
	int		i;

	i = -1;
	fdf->map->min_coeff = 0;
	while (++i < nbr_line)
	{
		list_content = list_pars->content;
		fdf->map->tab[i] = malloc(sizeof(int) * nbr_word);
		if (!fdf->map->tab[i])
			return (ft_freetabi(&fdf->map->tab, i), 0);
		set_map_z(fdf, nbr_word, list_content, i);
		list_pars = list_pars->next;
	}
	return (1);
}

static void	init_struct_map(t_fdf *fdf, t_list **list_pars, int nbr_line,
																int nbr_word)
{
	fdf->map->height = nbr_line;
	fdf->map->width = nbr_word;
	fdf->map->tab = malloc(sizeof(int *) * nbr_line);
	protect_alloc_list(fdf, (int **)fdf->map->tab, (void **)list_pars, \
		"for 'fdf->map->tab' in 'init_struc'");
	fdf->map->max_coeff = 0;
}

void	parsing(char *path, t_fdf *fdf)
{
	t_list	*list_pars;
	int		nbr_line;
	int		fd;
	int		is_filled;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_fdf(fdf, PERROR, path, 0);
	list_pars = NULL;
	nbr_line = read_file(&list_pars, fdf, fd);
	close(fd);
	count_word(fdf, list_pars);
	if (!fdf->map->map_valid)
	{
		ft_lstclear(&list_pars, free);
		exit_fdf(fdf, MAP_ERR, "", 0);
	}
	init_struct_map(fdf, &list_pars, nbr_line, fdf->map->width);
	is_filled = fill_tab(list_pars, fdf, nbr_line, fdf->map->width);
	ft_lstclear(&list_pars, free);
	if (!is_filled)
		exit_fdf(fdf, MALLOC_ERR, "for 'fdf->map->tab[i]' in 'fill_tab'", 0);
}

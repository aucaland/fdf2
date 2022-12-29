/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:13:28 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/29 17:58:53 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	count_word(t_fdf *fdf, t_list *list)
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
	return (fdf->map->width);
}

static int	read_file(t_list **list_pars, t_fdf *fdf, int fd)
{
	char	*str;
	t_list	*new;
	int		count_line;

	count_line = 0;
	while ((str = get_next_line(fd)) != NULL)
	{
		new = ft_lstnew(str);
		if (new == NULL)
		{
			ft_putstr_fd("New item List creation Failed", 2);
			ft_lstclear(list_pars, free);
			ft_free_fdf(fdf, -1);
		}
		ft_lstadd_back(list_pars, new);
		//free(str);
		count_line++;
	}
	fdf->map->nbr_line = count_line;
	return (count_line);
}

static void	*fill_tab(t_list *list_pars, t_fdf *fdf, int nbr_line, int nbr_word)
{
	char	*list_content;
	int		i;
	int		j;

	i = -1;
	while (++i < nbr_line)
	{
		list_content = list_pars->content;
		fdf->map->tab[i] = malloc(sizeof(int) * nbr_word);
		if (!fdf->map->tab[i])
			return (ft_freetabi(fdf->map->tab, nbr_word), ft_free_fdf(fdf, -1), NULL);
		j = 0;
		while (j < nbr_word)
		{
			while (*list_content != '\0' && ft_isspace(*list_content))
				list_content++;
			fdf->map->tab[i][j] = ft_atoi((list_content));
			fdf->map->max_coeff = fmax(fdf->map->max_coeff, fdf->map->tab[i][j]);
			fdf->map->min_coeff = fmin(fdf->map->min_coeff, fdf->map->tab[i][j++]);
			while (*list_content != '\0' && !ft_isspace(*list_content))
				list_content++;
		}
		list_pars = list_pars->next;
	}
	ft_lstclear(&list_pars, &free);
	return (NULL);
}

static t_fdf *init_struct_map(t_fdf *fdf, int nbr_line, int nbr_word)//TODO: init all struct
{
	fdf->map->height = nbr_line;
	fdf->map->width = nbr_word;
	fdf->map->tab = malloc(sizeof(int *) * nbr_line);
	if (!(fdf->map->tab))
		ft_free_fdf(fdf, -1);
	fdf->map->max_coeff = 0;
	return (fdf);
}

void	parsing(char *path, t_fdf *fdf)
{
	t_list	*list_pars;
	int		nbr_line;
	int		nbr_word;
	int		fd;

	fdf->map->height = fdf->map->width = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror(path);
		exit(EXIT_FAILURE);
	}
	list_pars = NULL;
	nbr_line = read_file(&list_pars, fdf, fd);
	close(fd);
	if (nbr_line <= 0 || list_pars == NULL)
	{
		ft_putstr_fd("Empty file or illegal content", 2);
		ft_free_fdf(fdf, -1);
	}
	nbr_word = count_word(fdf, list_pars);
	fdf = init_struct_map(fdf, nbr_line, nbr_word);
	fill_tab(list_pars, fdf, nbr_line, nbr_word);
	ft_lstclear(&list_pars, free);
}

//void ft_print_map(t_fdf *fdf)
//{
//	int i;
//	int j;
//
//	i = 0;
//	while (i < fdf->map->height)
//	{
//		j = 0;
//		while (j < fdf->map->width)
//			ft_printf("%d ", fdf->map->tab[i][j++]);
//		ft_printf("\n");
//		i++;
//	}
//}
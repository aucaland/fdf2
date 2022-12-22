/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:13:28 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/22 19:09:01 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
# include <time.h>

static int	count_word(t_list *list)
{
	int		i;
	int		nbr_word;
	int		comp;
	char	*content;

	i = 0;
	nbr_word = 0;
	content = list->content;
	while ((content)[i])
	{
		comp = 0;
		while (content[i] && ft_isspace(content[i]))
			i++;
		while (content[i] && !ft_isspace(content[i]) && content[i])
		{
			i++;
			comp++;
		}
		if (comp > 0)
			nbr_word++;
	}
	return (nbr_word);
}

static int	read_file(t_list **list_pars, t_fdf *fdf, int fd)
{
	char	*str;
	int		count_line;

	count_line = 0;
	while ((str = get_next_line(fd)) != NULL)
	{
		ft_lstadd_back(list_pars, ft_lstnew(ft_strdup(str)));
		free(str);
		count_line++;
	}
	fdf->map->nbr_line = count_line;
	return (count_line);
}

static void	fill_tab(t_list *list_pars, t_fdf *fdf, int nbr_line, int nbr_word)
{
	t_list	*top;
	char	*list_content;
	int		i;
	int		j;

	i = 0;
	top = list_pars;
	while (i < nbr_line)
	{
		list_content = list_pars->content;
		fdf->map->tab[i] = malloc(sizeof(int) * nbr_word);
		if (!fdf->map->tab[i])
		{
			ft_freetabi(fdf->map->tab, nbr_word);
			break ;
		}
		j = 0;
		while (j < nbr_word)
		{
			while (ft_isspace(*list_content))
				list_content++;
			fdf->map->tab[i][j] = ft_atoi((list_content));
			fdf->map->max_coeff = fmax(fdf->map->max_coeff, fdf->map->tab[i][j]);
			fdf->map->min_coeff = fmin(fdf->map->min_coeff, fdf->map->tab[i][j++]);
			while (!ft_isspace(*list_content))
				list_content++;
		}
		list_pars = list_pars->next;
		i++;
	}
	ft_lstclear(&top, &free);
}

static t_fdf *init_struct_map(t_fdf *fdf, int nbr_line, int nbr_word)//TODO: init all struct
{
	fdf->map->height = nbr_line;
	fdf->map->width = nbr_word;
	fdf->map->tab = malloc(sizeof(int *) * nbr_line);
	if (!(fdf->map->tab))
		ft_free_fdf(fdf, -1);
	return (fdf);
}

void	parsing(char *path, t_fdf *fdf)
{
	t_list	*list_pars;
	int		nbr_line;
	int		nbr_word;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror(path);
		exit(EXIT_FAILURE);
	}
	list_pars = NULL;
	nbr_line = read_file(&list_pars, fdf, fd);
	close(fd);
	if (nbr_line <= 0)
	{
		ft_putstr_fd("Empty file or illegal content", 2);
		ft_free_fdf(fdf, -1);
	}
	nbr_word = count_word(list_pars);
	fdf = init_struct_map(fdf, nbr_line, nbr_word);
	fdf->map->max_coeff = 0;
	fill_tab(list_pars, fdf, nbr_line, nbr_word);
	if (!fdf->map->tab)
		ft_free_fdf(fdf, -1);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurel <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:13:28 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/04 22:40:35 by aurel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	count_word(t_list *list)
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
		while (list_content[i] && ft_isspace(list_content[i]))
			i++;
		while (list_content[i] && !ft_isspace(list_content[i]) && list_content[i])
		{
			i++;
			comp++;
		}
		if (comp > 0)
			nbr_word++;
	}
	return (nbr_word);
}

static int	read_file(t_list **list_pars, int fd)
{
	char	*str;
	int		count_line;

	count_line = 0;
	str = get_next_line(fd);
	while (str != NULL)
	{
		ft_lstadd_back(list_pars, ft_lstnew(ft_strdup(str)));
//		dprintf(1, "%s\n", (char *)(*list_pars)->content);
		free(str);
		count_line++;
		str = get_next_line(fd);
	}
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
	fdf->map->max_coeff = 0;
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
			while (ft_isspace(*list_content))
				list_content++;
			fdf->map->tab[i][j] = ft_atoi((list_content));
			fdf->map->max_coeff = fmax(fdf->map->max_coeff, fdf->map->tab[i][j]);
			while (!ft_isspace(*list_content))
				list_content++;
			j++;
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
		return (ft_free(fdf->map, sizeof(t_map)), ft_free(fdf, sizeof(t_fdf)), NULL);
	return (fdf);
}

void	parsing(char *path, t_fdf *fdf)
{
	t_list	*list_pars;
//	char	*list_content;
	int		nbr_line;
	int		nbr_word;
	int fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit(-1);
	list_pars = NULL;
//	ft_printf("%s", path);
	nbr_line = read_file(&list_pars, fd);
	if (nbr_line <= 0)
		exit(-1);
//	list_content = list_pars->content;
//	dprintf(1, "%s\n", (char *)list_pars->content);
	nbr_word = count_word(list_pars);
//	dprintf(1, "%d\n", nbr_word);
	fdf = init_struct_map(fdf, nbr_line, nbr_word);
//	dprintf(1, "%s", (char *)list_pars->content);
//	dprintf(1, "%d", nbr_word);
	fill_tab(list_pars, fdf, nbr_line, nbr_word);
	ft_printf("%d", fdf->map->max_coeff );
//	ft_print_map(fdf);
	close (fd);
//	ft_printf("%d", fdf->map->tab[0][0]);
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
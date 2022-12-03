/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aucaland <aucaland@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:20:14 by aucaland          #+#    #+#             */
/*   Updated: 2022/12/02 11:39:03 by aucaland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*save_rest(char *line_buf)
{
	char	*str;
	int		i;

	i = 0;
	while (line_buf[i] && line_buf[i] != '\n')
		i++;
	if (line_buf[i] == '\n')
		str = ft_substr_gnl(line_buf, i + 1, ft_strlen_gnl(line_buf) - i + 1);
	else
		str = NULL;
	free(line_buf);
	line_buf = NULL;
	return (str);
}

static char	*get_correct_line(char *line_buf)
{
	char	*str;
	int		i;

	i = 0;
	while (line_buf[i] && line_buf[i] != '\n')
		i++;
	str = ft_substr_gnl(line_buf, 0, i + 1);
	return (str);
}

static char	*get_line_buf(int fd, char *line_buf)
{
	char	*buf;
	ssize_t	lenght;

	buf = ft_calloc_gnl(sizeof(char), BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	lenght = -1;
	while (!ft_strchr_gnl(buf, '\n') && lenght != 0)
	{
		lenght = read(fd, buf, BUFFER_SIZE);
		if (lenght == -1)
		{
			free(buf);
			buf = NULL;
			return (NULL);
		}
		buf[lenght] = '\0';
		if (buf[0] != 0)
			line_buf = ft_strjoin_gnl(line_buf, buf);
	}
	free(buf);
	buf = NULL;
	return (line_buf);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*line_buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(line_buf);
		line_buf = NULL;
		return (NULL);
	}
	line_buf = get_line_buf(fd, line_buf);
	if (!line_buf || line_buf[0] == '\0')
	{
		free(line_buf);
		line_buf = NULL;
		return (NULL);
	}
	line = get_correct_line(line_buf);
	line_buf = save_rest(line_buf);
	if (!line_buf || *line_buf == '\0')
	{
		free(line_buf);
		line_buf = NULL;
	}
	return (line);
}

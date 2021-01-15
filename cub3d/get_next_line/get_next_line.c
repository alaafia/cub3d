/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaafia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 17:02:18 by alaafia           #+#    #+#             */
/*   Updated: 2020/01/20 18:22:49 by alaafia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				get_line(char **sta, int n, char **line, int fd)
{
	char	*temp;
	int		i;

	i = 0;
	while (sta[fd][i] && sta[fd][i] != '\n')
		i++;
	*line = ft_substr(sta[fd], 0, i);
	if (!sta[fd][i])
	{
		temp = sta[fd];
		sta[fd] = NULL;
		free(temp);
		return (0);
	}
	else
	{
		temp = sta[fd];
		sta[fd] = ft_strdup((sta[fd]) + i + 1);
		free(temp);
	}
	if (!sta[fd] || !*line)
		return (-1);
	if (n || (n == 0 && sta[fd] != NULL))
		return (1);
	return (-1);
}

int				get_next_line(int fd, char **line)
{
	char			*buf;
	static char		*sta[4864];
	char			*temp;
	int				n;

	buf = NULL;
	if (!line || fd < 0 || fd >= 4864 || BUFFER_SIZE <= 0
			|| !(buf = malloc(BUFFER_SIZE + 1)) || read(fd, buf, 0) == -1)
		return (-1);
	if (!sta[fd])
		if (!(sta[fd] = ft_strdup("")))
			return (-1);
	while ((n = read(fd, buf, BUFFER_SIZE)))
	{
		temp = sta[fd];
		buf[n] = '\0';
		if (!(sta[fd] = ft_strjoin(sta[fd], buf)))
			return (-1);
		free(temp);
		if (ft_strchr(sta[fd], '\n') != 0)
			break ;
	}
	free(buf);
	return (get_line(sta, n, line, fd));
}

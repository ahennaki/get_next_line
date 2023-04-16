/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:30:06 by aennaki           #+#    #+#             */
/*   Updated: 2022/11/19 18:09:19 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_free(char **res, int fd)
{
	free(res[fd]);
	res[fd] = NULL;
}

static char	*ft_read_file(char **res, int fd)
{
	char	*buf;
	char	*temp;
	int		c;

	if (!res[fd])
		res[fd] = ft_calloc(1, 1);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	c = 1;
	while (c && !ft_strchr(res[fd], '\n'))
	{
		c = read(fd, buf, BUFFER_SIZE);
		if (c == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[c] = '\0';
		temp = ft_strjoin(res[fd], buf);
		ft_free(res, fd);
		res[fd] = temp;
	}
	free(buf);
	return (res[fd]);
}

static char	*ft_get_line(char **res, int fd)
{
	char	*temp;
	char	*str;
	int		i;
	int		j;

	if (ft_strlen(res[fd]) && !ft_strchr (res[fd], '\n'))
	{
		temp = ft_substr(res[fd], 0, ft_strlen(res[fd]));
		ft_free(res, fd);
		return (temp);
	}
	else if (ft_strchr (res[fd], '\n'))
	{
		i = ft_strlen(res[fd]);
		j = ft_strlen(ft_strchr(res[fd], '\n'));
		temp = ft_substr(res[fd], 0, i - j + 1);
		str = ft_substr(ft_strchr(res[fd], '\n'), 1, j + 1);
		ft_free(res, fd);
		res[fd] = str;
		return (temp);
	}
	ft_free(res, fd);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*res[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	res[fd] = ft_read_file(res, fd);
	if (!res[fd])
		return (NULL);
	line = ft_get_line(res, fd);
	return (line);
}

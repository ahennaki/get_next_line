/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aennaki <aennaki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:31:43 by aennaki           #+#    #+#             */
/*   Updated: 2022/11/16 17:54:33 by aennaki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free(char **res)
{
	free(*res);
	*res = NULL;
}

static char	*ft_joinres(char *res, char *buf)
{
	char	*temp;

	temp = ft_strjoin(res, buf);
	ft_free(&res);
	return (temp);
}

static char	*ft_read_file(int fd, char *res)
{
	char	*buf;
	int		c;

	if (!res)
		res = ft_calloc(1, 1);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	c = 1;
	while (c && !ft_strchr(res, '\n'))
	{
		c = read(fd, buf, BUFFER_SIZE);
		if (c == -1)
		{
			ft_free(&buf);
			return (NULL);
		}
		buf[c] = '\0';
		res = ft_joinres(res, buf);
	}
	ft_free(&buf);
	return (res);
}

static char	*ft_get_line(char **res)
{
	char	*temp;
	char	*str;
	int		i;
	int		j;

	if (ft_strlen(*res) && !ft_strchr (*res, '\n'))
	{
		temp = ft_substr(*res, 0, ft_strlen(*res));
		ft_free(res);
		return (temp);
	}
	else if (ft_strchr (*res, '\n'))
	{
		i = ft_strlen(*res);
		j = ft_strlen(ft_strchr(*res, '\n'));
		temp = ft_substr(*res, 0, i - j + 1);
		str = ft_substr(ft_strchr(*res, '\n'), 1, j + 1);
		ft_free(res);
		*res = str;
		return (temp);
	}
	ft_free(res);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*res;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	res = ft_read_file(fd, res);
	if (!res)
		return (NULL);
	line = ft_get_line(&res);
	return (line);
}

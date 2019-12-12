/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 23:49:20 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/14 23:49:23 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoinf(char *s1, char *s2)
{
	char	*ret;

	if ((ret = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	ft_strcpy(ret, s1);
	ft_strcat(ret, s2);
	free((char*)s1);
	return (ret);
}

static int	ft_read_line(int fd, char **buf, char **line, char *pos)
{
	int	result;

	*line = ft_strdup(*buf);
	while (!pos)
	{
		if ((result = read(fd, *buf, BUFF_SIZE)) < 0)
			return (-1);
		if ((pos = ft_strchr(*buf, '\n')) == NULL && !result)
			return ((*buf)[0] = 0);
		else if (pos)
		{
			(*buf)[result] = result ? 0 : (*buf)[result];
			pos[0] = 0;
			*line = ft_strjoinf(*line, *buf);
			ft_strcpy(*buf, pos + 1);
		}
		else
		{
			(*buf)[result] = result ? 0 : (*buf)[result];
			*line = ft_strjoinf(*line, *buf);
			(*buf)[0] = 0;
		}
	}
	return (*line ? 1 : -1);
}

int			get_next_line(int const fd, char **line)
{
	static char *buf;
	char		*pos;
	int			result;

	if (BUFF_SIZE < 1 || !line)
		return (-1);
	if (!buf)
		if (!(buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (-1);
	pos = ft_strchr(buf, '\n');
	if (pos)
	{
		*pos = 0;
		*line = ft_strdup(buf);
		ft_strcpy(buf, pos + 1);
		return (*line ? 1 : -1);
	}
	else
		result = ft_read_line(fd, &buf, line, NULL);
	if (result == 0 && ft_strlen(*line) == 0)
		free(buf);
	if (result == -1)
		return (-1);
	return (result ? 1 : ft_strlen(*line) != 0);
}

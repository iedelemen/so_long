/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:30:39 by idelemen          #+#    #+#             */
/*   Updated: 2024/01/11 15:23:33 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static char	*ft_copy_to_stash(char *stash, char *buf)
{
	char	*res;

	res = 0;
	if (!stash && buf)
	{
		res = ft_strdup(buf);
		if (!res)
			return (NULL);
		return (res);
	}
	res = ft_strjoin(stash, buf);
	ft_free_stash(&stash, 0);
	return (res);
}

static int	ft_have_nl(char *stash)
{
	size_t	i;

	if (!stash)
		return (0);
	i = -1;
	while (stash[++i] != '\0')
		if (stash[i] == '\n')
			return (1);
	return (0);
}

static char	*ft_extract_line(char *stash)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!stash)
		return (ft_free_stash(&stash, 0));
	while (stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (ft_free_stash(&line, 0));
	j = 0;
	while (j < i + 1)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

static char	*ft_recreate_stash(char *stash)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\n')
		i++;
	if (stash[i + 1] == '\0')
		return (ft_free_stash(&stash, 0));
	res = ft_substr(stash, i + 1, ft_strlen(stash));
	if (!res)
	{
		ft_free_stash(&stash, 0);
		return (NULL);
	}
	ft_free_stash(&stash, 0);
	return (res);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	long		ret;
	static char	*stash = NULL;
	char		*line;

	line = 0;
	ret = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if ((ret <= 0 && !stash) || ret == -1)
			return (ft_free_stash(&stash, 0));
		buf[ret] = '\0';
		stash = ft_copy_to_stash(stash, buf);
		if (ft_have_nl(stash))
		{
			line = ft_extract_line(stash);
			if (!line)
				return (ft_free_stash(&stash, 0));
			return (stash = ft_recreate_stash(stash), line);
		}
	}
	return (ft_free_stash(&stash, 1));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:36:39 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/08 14:52:37 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd)
{
	char	*buffer;
	int		red;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	red = read(fd, buffer, BUFFER_SIZE);
	if (red < 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[red] = '\0';
	return (buffer);
}

static char	*ft_read_next(int fd, char *last_buffer)
{
	char	*new;
	char	*dest;

	dest = ft_read(fd);
	if (!dest)
		return (NULL);
	else if (!dest[0])
	{
		free (dest);
		return (last_buffer);
	}
	else if (!last_buffer)
		return (dest);
	new = ft_strjoin(last_buffer, dest);
	free (last_buffer);
	free (dest);
	return (new);
}

static char	*ft_find_nl(char *buffer, char *line)
{
	char	*new;
	size_t	lenght;

	if (!buffer || !line)
		return (NULL);
	lenght = ft_strlen(line);
	if (lenght == ft_strlen(buffer))
	{
		free(buffer);
		return (NULL);
	}
	new = ft_substr(buffer, lenght, (ft_strlen(buffer) - lenght));
	free(buffer);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*line;
	size_t		lenght;

	if (fd < 0)
		return (NULL);
	line = 0;
	if (ft_strchr_(cache, '\n') == -1)
	{
		lenght = ft_strlen(cache);
		cache = ft_read_next(fd, cache);
		if (lenght == ft_strlen(cache) && cache)
			line = ft_substr(cache, 0, lenght);
	}
	if (!cache)
		return (NULL);
	if (!line && ft_strchr_(cache, '\n') != -1)
		line = ft_substr(cache, 0, (ft_strchr_(cache, '\n') + 1));
	if (line)
	{
		cache = ft_find_nl(cache, line);
		return (line);
	}
	return (get_next_line(fd));
}

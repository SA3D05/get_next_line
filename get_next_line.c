/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satifi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:15:40 by satifi            #+#    #+#             */
/*   Updated: 2025/11/07 15:35:23 by satifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*handel_result(char *line)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (!line || !*line)
		return (free(line), NULL);
	i = 0;
	j = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	result = malloc((i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (j < i)
	{
		result[j] = line[j];
		j++;
	}
	result[j] = '\0';
	free(line);
	return (result);
}

char	*get_line(char *buffer)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	while (buffer[i])
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
	line = ft_strdup(buffer);
	return (line);
}

char	*handel_ret(ssize_t ret, char **buffer, char *line)
{
	if (ret == -1)
	{
		free(*buffer);
		*buffer = NULL;
		if (line)
			free(line);
		return (NULL);
	}
	else
	{
		free(*buffer);
		*buffer = NULL;
		return (handel_result(line));
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	ssize_t		ret;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (buffer)
		line = get_line(buffer);
	else
	{
		buffer = malloc(((size_t)BUFFER_SIZE + (size_t)1) * sizeof(char));
		if (!buffer)
			return (NULL);
	}
	while (!has_newline(line))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1 || ret == 0)
			return (handel_ret(ret, &buffer, line));
		buffer[ret] = '\0';
		line = ft_strjoin(line, buffer);
	}
	return (handel_result(line));
}

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

int has_newline(const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// hello \nworld
//         i
char *handel_result(char *str)
{
	size_t i;
	size_t j;
	char *line;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (i == 0)
	{
		free(str);
		return (NULL);
	}
	line = malloc((i + 1) * sizeof(char));
	while (j < i)
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	free(str);
	return (line);
}

char *buffer_filled(char *buffer)
{
	char *line;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	while (buffer[i])
		buffer[j++] = buffer[i++];
	buffer[j] = '\0';
	line = ft_strdup(buffer);
	return (line);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char *line;
	ssize_t ret;
	// static int i = 1;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (buffer)
		line = buffer_filled(buffer);
	else
	{
		buffer = malloc(((size_t)BUFFER_SIZE + (size_t)1) * sizeof(char));
		if (!buffer)
			return (NULL);
	}
	while (!has_newline(line))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		if (ret == 0)
			return (handel_result(line));
		buffer[ret] = '\0';

		line = ft_strjoin(line, buffer);
		// fprintf(stderr, "GNL %d:\nbuffer: %s|\tline: %s|\n", i++, buffer, line);
		if (!line)
			return (NULL);
	}
	return (handel_result(line));
}

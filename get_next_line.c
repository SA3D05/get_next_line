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

char *handel_result(char *str)
{
	size_t i;
	size_t j;
	char *result;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	result =malloc((i + 1) * sizeof(char));
	while (j < i)
	{
		result[j] = str[j];
		j++;
	}
	result[i] = '\0';
	free(str);
	return (result);
}

void clean_buffer(char *buffer, size_t start)
{
	size_t i;

	i = 0;
	while (buffer[start])
		buffer[i++] = buffer[start++];
	buffer[start] = '\0';
}

void buffer_filled(char **str, char *buffer)
{
	size_t start;
	size_t k;
	size_t size;
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	size = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	start = i;
	while (buffer[i])
	{
		size += 1;
		i++;
	}
	*str = malloc(size + 1);
	k = start;
	while (start < i)
		str[0][j++] = buffer[start++];
	str[0][j] = '\0';
	clean_buffer(buffer, k);
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char *str;
	ssize_t ret;

	str = NULL;
	if (*buffer)
		buffer_filled(&str, buffer);
	while (!has_newline(str))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return (NULL);
		if (ret == 0)
			return (handel_result(str));
		buffer[ret] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
	}
	return (handel_result(str));
}

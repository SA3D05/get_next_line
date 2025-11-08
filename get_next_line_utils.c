/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satifi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:23:06 by satifi            #+#    #+#             */
/*   Updated: 2025/11/07 15:04:47 by satifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(const char *s)
{
	size_t i;
	size_t len;
	char *result;

	i = 0;
	len = ft_strlen(s);
	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char *ft_strjoin(char *s1, char const *s2)
{
	size_t s1_l;
	size_t s2_l;
	size_t i;
	size_t result_i;
	char *result;

	if (!s1)
		return (ft_strdup(s2));
	i = 0;
	result_i = 0;
	s2_l = ft_strlen(s2);
	s1_l = ft_strlen(s1);
	result = malloc(s1_l + s2_l + 1);
	if (!result)
		return (NULL);
	while (s1[i])
		result[result_i++] = s1[i++];
	i = 0;
	while (s2[i])
		result[result_i++] = s2[i++];
	result[result_i] = '\0';
	free(s1);
	return (result);
}

// hello \nworld
//         i

char *cat(char *buffer, size_t start)
{
	size_t i;
	size_t j;
	size_t size;
	char *result;

	i = start;
	size = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		size += 1;
		i += 1;
	}
	result = malloc(size + 1);
	if (!result)
		return (NULL);
	while (start < i)
		result[j++] = buffer[start++];
	result[j] = '\0';
	return (result);
}

char *ft_strchr(const char *s, int c)
{
	size_t i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satifi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:23:06 by satifi            #+#    #+#             */
/*   Updated: 2025/11/09 11:38:07 by satifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	has_newline(const char *str)
{
	int	i;

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

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*result;

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

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	s1_l;
	size_t	s2_l;
	size_t	i;
	size_t	result_i;
	char	*result;

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

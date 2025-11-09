/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satifi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:22:57 by satifi            #+#    #+#             */
/*   Updated: 2025/11/07 15:00:35 by satifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

char *ft_strdup(const char *s);
char *get_next_line(int fd);
char *ft_strjoin(char *s1, char const *s2);
size_t ft_strlen(const char *str);
int	has_newline(const char *str);

#endif
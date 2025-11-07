/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satifi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:22:57 by satifi            #+#    #+#             */
/*   Updated: 2025/11/07 14:44:05 by satifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 6434354
#endif

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void counter();
char *get_next_line(int fd);
char *ft_strjoin(char const *s1, char const *s2);
void ft_bzero(void *s, size_t n);
size_t ft_strlen(const char *str);

#endif
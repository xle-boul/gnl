/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:55:24 by xle-boul          #+#    #+#             */
/*   Updated: 2021/12/12 14:27:33 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_mallocable(char *patch)
{
	int		i;
	char	*str;

	i = 0;
	if (!patch[i])
		return (NULL);
	while (patch[i] && patch[i] != '\n')
		i++;
	if (patch[i] == '\n')
		str = malloc(sizeof(char) * (i + 2));
	else if (patch[i] == '\0')
		str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	return (str);
}

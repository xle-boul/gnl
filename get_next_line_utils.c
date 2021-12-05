/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:48:54 by xle-boul          #+#    #+#             */
/*   Updated: 2021/12/05 15:18:49 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free_stuff(char *truc)
{
	if (truc)
		free(truc);
	return ;
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (dst);
	while (i < size && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

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

char	*ft_add_last(char *line, char c)
{
	int		i;
	char	*temp;

	i = 0;
	if (line == NULL)
	{
		temp = malloc(sizeof(char) * 2);
		if (!temp)
			return (NULL);
		temp[0] = c;
		temp[1] = '\0';
	}
	else
	{
		while (line[i] != '\0')
			i++;
		temp = malloc(sizeof(char) * (i + 1));
		if (!temp)
			return (NULL);
		ft_strcpy(temp, line, i);
		temp[i] = c;
		temp[i + 1] = '\0';
	}
	ft_free_stuff(line);
	return (temp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*new;
	size_t		i;

	i = 0;
	if (len < ft_strlen(s))
		new = (char *)malloc(sizeof(char) * len + 1);
	else
		new = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	if (start > ft_strlen(s))
	{
		new[i] = '\0';
		return (new);
	}
	while (i <= len - 1 && s[i + start] != '\0' && len > 0)
	{
		new[i] = s[i + start];
		i++;
	}
	new[i] = '\0';
	return (new);
}

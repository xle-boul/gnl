/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:55:40 by xle-boul          #+#    #+#             */
/*   Updated: 2021/12/14 20:40:23 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_that_line(char *patch)
{
	int		i;
	char	*str;

	str = ft_mallocable(patch);
	if (!str)
		return (NULL);
	i = 0;
	while (patch[i] && patch[i] != '\n')
	{
		str[i] = patch[i];
		i++;
	}
	if (patch[i] == '\n')
	{
		str[i] = patch[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_patch(char *patch)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (patch[i] && patch[i] != '\n')
		i++;
	if (!patch[i])
	{
		free(patch);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(patch) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (patch[i])
		str[j++] = patch[i++];
	str[j] = '\0';
	free(patch);
	return (str);
}

char	*ft_strjoin_gnl(char *patch, char *buf)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!patch)
	{
		patch = malloc(sizeof(char) * 1);
		patch[0] = '\0';
	}
	if (!patch || !buf)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(patch) + ft_strlen(buf)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (patch)
		while (patch[++i] != '\0')
			str[i] = patch[i];
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	str[i] = '\0';
	free(patch);
	return (str);
}

char	*ft_feed_patch(int fd, char *patch)
{
	char	buf[BUFFER_SIZE + 1];
	int		end;

	end = 1;
	while (!ft_strchr(patch, '\n') && end != 0)
	{
		end = read(fd, buf, BUFFER_SIZE);
		if (end == -1)
			return (NULL);
		buf[end] = '\0';
		patch = ft_strjoin_gnl(patch, buf);
	}
	return (patch);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*patch;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	patch = ft_feed_patch(fd, patch);
	if (!patch)
		return (NULL);
	line = ft_get_that_line(patch);
	patch = ft_new_patch(patch);
	return (line);
}

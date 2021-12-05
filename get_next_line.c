/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:44:33 by xle-boul          #+#    #+#             */
/*   Updated: 2021/12/02 13:40:44 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		return (temp);
	}
	while (line[i] != '\0')
		i++;
	temp = malloc(sizeof(char) * (i + 1));
	if (!temp)
		return (NULL);
	temp = ft_substr(line, 0, i);
	temp[i] = c;
	temp [i + 1] = '\0';
	free (line);
	return (temp);
}

char	*get_line(char *buf, int end)
{
	static char	*patch;
	char		*line;
	int			i;

	i = 0;
	if (patch)
	{
		while (patch[i] != '\0')
		{
			if (patch[i] == '\n')
			{
				i++;
				line = ft_substr(patch, 0, i);
				patch = ft_substr(patch, i, ft_strlen(patch) - i + 1);
				return (line);
			}
			i++;
		}
		if (end == 0)
		{
			line = patch;
			patch = NULL;
			return (line);
		}
	}
	i = 0;
	while (buf[i] != '\0')
	{
		patch = ft_add_last(patch, buf[i]);
		if (buf[i] == '\n')
		{
			i++;
			line = patch;
			patch = NULL;
			if (i < BUFFER_SIZE)
				patch = ft_substr(buf, i, BUFFER_SIZE + 1);
			return (line);
		}
		i++;
	}
}

char	*get_next_line(int fd)
{
	char			*line;
	char			buf[BUFFER_SIZE + 1];
	int				end;

	line = NULL;
	while (buf)
	{
		end = read(fd, buf, BUFFER_SIZE);
		buf[end] = '\0';
		line = get_line(buf, end);
		if (line)
			return (line);
		else if (end == 0 || fd < 1)
			return (NULL);
	}
}

int main(int ac, char *av[])
{
	int		fd;
	char	*line;

	// fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	free(line);
	close (fd);
	return (0);
}

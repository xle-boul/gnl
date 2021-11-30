/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:44:33 by xle-boul          #+#    #+#             */
/*   Updated: 2021/11/30 16:37:17 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
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

char	*get_next_line(int fd)
{
	char			*line;
	char			buf[BUFFER_SIZE + 1];
	int				i;
	int				end;
	static char		*patch;

	line = NULL;
	while (1)
	{
		end = read(fd, buf, BUFFER_SIZE);
		buf[end] = '\0';
		if (end == 0 || fd < 1)
			return (NULL);
		i = 0;
		if (patch)
		{
			line = patch;
			patch = NULL;
		}
		while (buf[i] != '\0')
		{
			line = ft_add_last(line, buf[i]);
			if (buf[i] == '\n')
			{
				i++;
				if (i < BUFFER_SIZE)
					patch = ft_substr(buf, i, BUFFER_SIZE + 1);
				else
					patch = NULL;
				return (line);
			}
			i++;
		}
		if (end == 0)
			break ;
	}
	return (line);
}

int main()
{
	int		fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close (fd);
	return (0);
}

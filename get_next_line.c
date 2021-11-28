/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:44:33 by xle-boul          #+#    #+#             */
/*   Updated: 2021/11/25 16:19:11 by xle-boul         ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
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


char	*get_next_line(int fd)
{
	char			*line;
	char			buf[BUFFER_SIZE + 1];
	static char		*patch;
	char			*temp;
	int				i;
	static int		count;
	int				end;

	end = read(fd, buf, BUFFER_SIZE);
	buf[end] = '\0';
	i = 0;
	line = (NULL);
	if (!patch)
		temp = buf;
	else if (patch)
		temp = patch;
	// printf("temp = %s\n", temp);
	while (temp[i] != '\0')
	{
		if (temp[i] == '\n')
		{
			line = ft_substr(temp, 0, (i + 1));
			patch = ft_substr(temp, (i + 1), BUFFER_SIZE);
			break ;
		}
		else if (temp[i + 1] == '\0' && temp[i] != '\n')
		{
			patch = ft_substr(buf, 0, BUFFER_SIZE);
			break ;
		}
		i++;
	}
	return (line);
}

int main()
{
	char	**line;
	int		fd;
	int		i;

	line = malloc(sizeof(char *) * 2);
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	line[0] = get_next_line(fd);
	line[1] = get_next_line(fd);
	line[2] = get_next_line(fd);
	printf("%s%s%s", line[0], line[1], line[2]);
	close (fd);
	
	return (0);
}
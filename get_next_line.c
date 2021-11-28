/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:44:33 by xle-boul          #+#    #+#             */
/*   Updated: 2021/11/28 16:54:34 by xle-boul         ###   ########.fr       */
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

char	*ft_strpaste(char *buf, char *temp)
{
	char	*new_temp;
	char	*old_temp;

	printf("buf = %s\n\n", buf);
	new_temp = NULL;
	old_temp = temp;
	if (!temp)
		new_temp = ft_substr(buf, 0, (ft_strlen(buf) + 1));
	if (temp)
	{
		new_temp = ft_strjoin(temp, buf);
		free(old_temp);
	}
	return (new_temp);
}

char	*get_next_line(int fd)
{
	char			*line;
	char			buf[BUFFER_SIZE + 1];
	static char		*patch;
	char			*temp;
	int				i;

	i = 0;
	temp = NULL;
	// while (read(fd, buf, BUFFER_SIZE) == BUFFER_SIZE)
	// 	temp = ft_strpaste(buf, temp);
	// temp = ft_strpaste(buf, temp);
	// printf("%s\n", temp);
	i = 0;
	line = (NULL);
	if (!patch)
		temp = buf;
	else
		temp = patch;
	while (temp[i] != '\0')
	{
		if (temp[i] == '\n')
		{
			line = ft_substr(temp, 0, (i + 1));
			patch = ft_substr(temp, (i + 1), BUFFER_SIZE);
			break ;
		}
		i++;
	}
	if (temp[i] == '\0')
		line = ft_substr(temp, 0, (i + 1));
	return (line);
}

int main()
{
	int		fd;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	close (fd);
	return 0;
}

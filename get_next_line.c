/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 20:44:33 by xle-boul          #+#    #+#             */
/*   Updated: 2021/12/05 15:19:56 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	else if (!patch)
	{
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
	return (NULL);
}

char	*get_next_line(int fd)
{
	char			*line;
	char			buf[BUFFER_SIZE + 1];
	int				end;

	line = NULL;
	while (1)
	{
		end = read(fd, buf, BUFFER_SIZE);
		buf[end] = '\0';
		line = get_line(buf, end);
		if (line)
			return (line);
		if (!line || end == 0)
		{
			//free all the shit we created
			return (NULL);
		}
	}
	return (NULL);
}

int main(int ac, char *av[])
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	get_next_line(fd);
	get_next_line(fd);
	free(line);
	close (fd);
	return (0);
}

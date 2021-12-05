/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 13:15:27 by xle-boul          #+#    #+#             */
/*   Updated: 2021/12/05 16:33:03 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_realloc_patch(char	*buf, char *patch)
{
	int		i;
	char	*temp;

	i = 0;
	temp = patch;
	free(patch);
	while (*temp == *buf)
	{
		temp++;
		buf++;
	}
	patch = malloc(sizeof(char) * (ft_strlen(buf) + 1));
	ft_strlcpy(patch, buf, (ft_strlen(buf) + 1));
	return (patch);
}

char	*ft_get_that_line(char *buf, char *line)
{
	int			i;
	static char	*patch;

	i = 0;
	printf("%s\n", buf);
	while (buf[i] != '\0')
	{
		patch = ft_add_last(patch, buf[i]);
		if (buf[i] == '\n')
		{
			i++;
			line = ft_substr(patch, 0, i);
			if (i < BUFFER_SIZE)
			{
				printf("pre %s\n", patch);
				patch = ft_realloc_patch(buf, patch);
				printf("post %s\n", patch);
			}
			break ;
		}
		i++;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	int		end;
	char	buf[BUFFER_SIZE + 1];
	char	*line;

	line = NULL;
	while (1)
	{
		end = read(fd, buf, BUFFER_SIZE);
		buf[end] = '\0';
		line = ft_get_that_line(buf, line);
		if (line)
			return (line);
		if (!line || end == 0)
			return (NULL);
	}
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("line is %s", line);
	free(line);
	return (0);
}

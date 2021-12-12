/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:09:18 by xle-boul          #+#    #+#             */
/*   Updated: 2021/12/12 13:57:27 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		fd1;
	int		fd2;
	int		fd3;
	fd1 = open("tests/test1.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	line = get_next_line(fd1);
	printf("%s", line);
	free(line);
	while (line)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		free(line);
	}
	line = get_next_line(fd2);
	printf("\n---------------------------------\n---------------------------------\n%s", line);
	free(line);
	while (line)
	{
		line = get_next_line(fd2);
		printf("%s", line);
		free(line);
	}
	line = get_next_line(fd3);
	printf("\n---------------------------------\n---------------------------------\n%s", line);
	free(line);
	while (line)
	{
		line = get_next_line(fd3);
		printf("%s", line);
		free(line);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}

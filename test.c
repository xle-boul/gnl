/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xle-boul <xle-boul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:59:00 by xle-boul          #+#    #+#             */
/*   Updated: 2021/12/05 15:45:29 by xle-boul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int main()
{
	char	*str;

	str = malloc(sizeof(char *) * 4);
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = '\0';
	printf("%s\n%s\n%s\n", str, str, str);
	free(str);
	return 0;
}

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xle-boul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/21 20:50:19 by xle-boul          #+#    #+#              #
#    Updated: 2021/11/22 19:40:03 by xle-boul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = get_next_line.c get_next_line_utils.c

CC = gcc

CC_FLAGS = -Werror -Wall -Wextra

BUF = -D BUFFER_SIZE=4

all:
	$(CC) $(CC_FLAGS) $(SRCS)

fd:
	$(CC) $(CC_FLAGS) $(BUF) $(SRCS)

clean:
	rm a.out

re: clean all

.PHONY: all fd re clean
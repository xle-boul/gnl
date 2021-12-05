# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xle-boul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/21 20:50:19 by xle-boul          #+#    #+#              #
#    Updated: 2021/12/01 11:22:40 by xle-boul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = get_next_line.c 

CC = gcc

# CC_FLAGS = -Werror -Wall -Wextra -g

BUF = -D BUFFER_SIZE=40

all:
	$(CC) $(CC_FLAGS) $(SRCS)

fd:
	$(CC) $(CC_FLAGS) $(BUF) $(SRCS)

clean:
	rm a.out

re: clean all

.PHONY: all fd re clean
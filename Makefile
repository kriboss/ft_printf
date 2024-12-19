# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbossio <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 11:19:36 by kbossio           #+#    #+#              #
#    Updated: 2024/12/02 13:06:06 by kbossio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc -Wall -Wextra -Werror

FILES =	ft_printf.c ft_printf_utils.c

OBJS = ${FILES:.c=.o}

${NAME}:
	${CC} -c ${FILES}
	ar -rcs ${NAME} ${OBJS}

%.o: %.c
	${CC} ${FILES} -c $< -o $@

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all, clean, fclean, re

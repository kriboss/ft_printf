# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 11:19:36 by kbossio           #+#    #+#              #
#    Updated: 2025/01/29 19:59:34 by kbossio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc -Wall -Wextra -Werror

FILES =	ft_printf.c ft_printf_utils.c

OBJS = ${FILES:.c=.o}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}
	
%.o: %.c
	${CC} -c $< -o $@

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re

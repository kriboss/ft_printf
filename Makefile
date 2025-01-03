# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 11:19:36 by kbossio           #+#    #+#              #
#    Updated: 2025/01/03 16:50:00 by kbossio          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc -Wall -Wextra -Werror

FILES =	ft_printf.c ft_printf_utils.c
BFILES = bonus/ft_printf_bonus.c bonus/ft_printf_string_bonus.c bonus/arg_check_bonus.c bonus/utils_bonus.c bonus/flags_bonus.c bonus/printing_bonus.c

OBJS = ${FILES:.c=.o}
BOBJS = ${BFILES:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

bonus: fclean $(BOBJS)
	ar -rcs	$(NAME)	$(BOBJS)

%.o: %.c
	${CC} -c $< -o $@

clean:
	rm -f ${OBJS} ${BOBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re

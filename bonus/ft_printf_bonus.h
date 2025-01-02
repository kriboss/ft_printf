/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:56:28 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/02 22:50:58 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_printf
{
	int width;
	int precision;
	int zero;
	int minus;
	int hash;
	int space;
	int plus;
}	s_printf;

int		ft_printf(const char *format, ...);

size_t	ft_putnbr_base(ssize_t nbr, char *base, const char type, char **flags);
size_t	ft_putstr_fd(const char *s);
size_t	ft_putchar_fd(const char c);
char	*ft_strchr(const char *str, int c);

int	arg_check(char *str, char **flags, char type, int sign);
int	minus(char *str, int amount);
int	padding(char *str, int amount, char c, char prefix);
int	point_num(char *str, int amount, char prefix);
int	point_str(char *str, int amount);
int	ft_atoi(const char *str);
size_t	isnumber(char c);
void	ft_memset(void *p, int c, size_t len);

#endif

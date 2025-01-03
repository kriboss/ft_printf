/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:56:54 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/03 01:29:30 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

s_printf	*init_flags(void)
{
	s_printf	*flags;

	flags = (s_printf *)malloc(sizeof(s_printf));
	if (!flags)
		return (NULL);
	flags->width = 0;
	flags->precision = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	return (flags);
}

void	check_flags(const char *opt, const char *f, s_printf *flags)
{
	int	i;

	i = 0;
	while (ft_strchr(opt, f[i + 1]))
	{
		if (f[i + 1] == '-')
			flags->minus = 1;
		else if (f[i + 1] == '0')
			flags->zero = 1;
		else if (f[i + 1] == '#')
			flags->hash = 1;
		else if (f[i + 1] == ' ')
			flags->space = 1;
		else if (f[i + 1] == '+')
			flags->plus = 1;
		i++;
	}
	while (isnumber(f[i + 1]))
	{
		flags->width = flags->width * 10 + (f[i + 1] - 48);
		i++;
	}
	if (f[i + 1] == '.')
	{
		flags->precision = 0;
		while (isnumber(f[i + 2]))
		{
			flags->precision = flags->precision * 10 + (f[i + 2] - 48);
			i++;
		}
	}
	printf("Flags: -%d 0%d #%d %d +%d Width: %d Precision: %d\n", 
		flags->minus, flags->zero, flags->hash, flags->space, flags->plus, 
		flags->width, flags->precision);
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				num;

	num = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13)
		|| str[i] == 32 || str[i] == '+' || str[i] == '-' || str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num);
}

size_t	isnumber(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	ft_memset(void *p, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)p;
	i = 0;
	while (i < len)
	{
		str[i] = c;
		i++;
	}
}
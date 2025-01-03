/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:31:52 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/03 17:41:22 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_flags	ft_init_flags(void)
{
	t_flags	flags;

	flags.minus = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.precision = 0;
	flags.star = 0;
	flags.type = 0;
	return (flags);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	flags;
	char	*start;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			start = (char *)format;
			if (*(++format))
				count += ft_pars((char *)format, args);
			while (*format && !ft_strchr(TYPE, *format))
				format++;
			if (!(*format))
				format = start;
		}
		else
			count += ft_putchar_fd(*format, 1);
		if (*format)
			format++;
	}
	va_end(args);
	return (count);
}
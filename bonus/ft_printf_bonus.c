/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:56:22 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/02 21:00:58 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

size_t	conv(const char type, va_list args, char **flags)
{
	char	*lhex;
	char	*uhex;
	size_t	count;

	lhex = "0123456789abcdef";
	uhex = "0123456789ABCDEF";
	count = 0;
	if (type == 'c')
		count += ft_putchar_fd(va_arg(args, int));
	else if (type == 's')
		count += ft_putstr_fd(va_arg(args, char *));
	else if (type == 'p')
		count += ft_putnbr_base(va_arg(args, long), lhex, type, flags);
	else if (type == 'd' || type == 'i')
		count += ft_putnbr_base(va_arg(args, int), "0123456789", type, flags);
	else if (type == 'u')
		count += ft_putnbr_base(va_arg(args, unsigned), "0123456789", type, flags);
	else if (type == 'x')
		count += ft_putnbr_base(va_arg(args, unsigned), lhex, type, flags);
	else if (type == 'X')
		count += ft_putnbr_base(va_arg(args, unsigned), uhex, type, flags);
	else if (type == '%')
		count += ft_putchar_fd('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	char	*type;
	char	**flags;
	char	*opt;
	int		i;
	int		j;
	int		count;
	va_list	args;

	va_start(args, format);
	type = "cspdiuxX%";
	i = 0;
	count = 0;
	opt = "-0.# +";
	flags = malloc(3 * sizeof(char *));
    if (!flags)
        return (0);
    flags[0] = malloc(32 * sizeof(char));
    flags[1] = malloc(32 * sizeof(char));
    flags[2] = malloc(32 * sizeof(char));
    if (!flags[0] || !flags[1] || !flags[2])
    {
        free(flags[0]);
        free(flags[1]);
        free(flags[2]);
        free(flags);
        return (0);
    }
	while (format[i])
	{
		if (format[i] == '%')
		{
			j = 0;
			while (j < 3 && flags[j])
			{
				ft_memset(flags[j], 0, 32);
				j++;
			}
			j = 0;
			while (ft_strchr(opt, format[i + 1]))
			{
				flags[0][j++] = format[i + 1];
				i++;
			}
			flags[0][j] = '\0';
			j = 0;
			while (isnumber(format[i + 1]))
			{
				flags[1][j++] = format[i + 1];
				i++;
			}
			flags[1][j] = '\0';
			if (format[i + 1] == '.')
			{
				j = 0;
				while (isnumber(format[i + 1]))
				{
					flags[2][j++] = format[i + 1];
					i++;
				}
				flags[2][j] = '\0';
			}
			if(ft_strchr(type, format[i + 1]))
			{
				count += conv(format[i + 1], args, flags);
				++i;
			}
		}
		else
			count += ft_putchar_fd(format[i]);
		i++;
	}
	free(flags[0]);
	free(flags[1]);
	free(flags[2]);
	free(flags);
	va_end(args);
	return (count);
}
/*
#include <stdio.h>

int main() {
    // Test %c with a character
    char c = 'A';
    printf("original: %c\n", c);
    ft_printf("ft_printf character: %c\n", c);


    // Test %d with an integer
    int num = 12345;
    printf("original: %d\n", num);
    ft_printf("ft_printf digit: %d\n", num);

    // Test %i with an integer (should be the same as %d)
    int num2 = -5678;
    printf("original: %i\n", num2);
    ft_printf("ft_printf integer: %i\n", num2);

    // Test %u with an unsigned integer
    unsigned int u_num = 4294967295;
    printf("original: %u\n", u_num);
    ft_printf("ft_printf unsigned integer: %u\n", u_num);

    // Test %x with a hexadecimal number
    int hex_num = 255;
    printf("original: %x\n", hex_num);
    ft_printf("ft_printf lower hexadecimal: %x\n", hex_num);

    // Test %X with a hexadecimal number (uppercase)
    printf("original: %X\n", hex_num);
    ft_printf("ft_printf upper hexadecimal: %X\n", hex_num);

    // Test %p with a pointer (memory address)

    // Test %% to print a literal %
    printf("original: %%\n");
    ft_printf("ft_printf character: %%\n");
    
    printf("printf test%d", printf("ft_printf character: %c\n", c));
    printf("%d", ft_printf("ft_printf character: %c\n", c));
    // Test %s with a string
    char *str = "Hello, ft_printf!";
    printf("original %s \n", str);
    ft_printf("ft_printf string: %s \n", str);
    
    int *ptr = &num;
    printf("original: %p\n", ptr);
    ft_printf("ft_printf pointer: %p\n", ptr);
    return 0;
}*/

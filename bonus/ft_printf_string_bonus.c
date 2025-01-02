/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:56:45 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/03 00:21:41 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	print_base(ssize_t nbr, char *base, char type, char **flags)
{
	int		i;
	char	ris[20] = {0};
	int		index;
	int		sign;

	i = 0;
	index = 0;
	sign = 1;
	while (base[i] != '\0')
		i++;
	if (nbr < 0 && (type == 'd' || type == 'i' || type == 'u'))
	{
		ft_putchar_fd('-');
		nbr = -nbr;
		sign = -1;
	}
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return (1);
	}
	while (nbr != 0)
	{
		ris[index] = base[nbr % i];
		nbr /= i;
		index++;
	}
	i = index;
	if (flags[0][0] != 0)
		i = arg_check(ris, flags, type, sign);
	else
	{
		while (--index >= 0)
			write(1, &ris[index], 1);
	}
	return (i);
}

size_t	ft_putnbr_base(ssize_t nbr, char *base, const char type, char **flags)
{
	size_t	i;
	size_t	cont;

	i = 0;
	cont = 0;
	while (base[i] != '\0')
		i++;
	if (type == 'p' && nbr == 0)
	{
		cont += ft_putstr_fd("(nil)");
		return (cont);
	}
	else if (type == 'p')
		cont += ft_putstr_fd("0x");
	return (cont + print_base(nbr, base, type, flags));
}

size_t	ft_putstr_fd(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr_fd("(null)"));
	while (s[i])
	{
		ft_putchar_fd(s[i]);
		i++;
	}
	return (i);
}

size_t	ft_putchar_fd(const char c)
{
	write(1, &c, 1);
	return (1);
}

char	*ft_strchr(const char *str, int c)
{
	while ((char)c != *str)
	{
		if (!*str)
			return (0);
		str++;
	}
	return ((char *)str);
}

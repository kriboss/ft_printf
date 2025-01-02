/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:56:06 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/03 00:06:22 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

int	arg_check(char *str, char **flags, char type, int sign)
{
	int		i;
	int		amount[2];
	int		count;
	char	prefix;

	i = 0;
	prefix = 0;
	count = 0;
	amount[0] = ft_atoi(flags[1]);
	amount[1] = ft_atoi(flags[2]);
	if (sign < 0)
	{
		amount[0]--;
		count++;
	}
	if (ft_strchr(flags[0], '#'))
	{
		if (type == 'x')
		{
			write(1, "0x", 2);
			count += 2;
		}
		else if (type == 'X')
		{
			write(1, "0X", 2);
			count += 2;
		}
	}
	if (ft_strchr(flags[0], '+'))
	{
		if (sign >= 0)
			prefix = '+';
		amount[0]--;
	}
	else if (ft_strchr(flags[0], ' '))
	{
		if (sign >= 0)
			prefix = '-';
		amount[0]--;
	}
	if (ft_strchr(flags[0], '-'))
	{
		if (prefix)
		{
			write(1, &prefix, 1);
			count++;
		}
		count += minus(str, amount[0]);
	}
	else if (ft_strchr(flags[0], '0'))
		count += padding(str, amount[0], '0', prefix);
	else if (ft_strchr(flags[0], '.'))
	{
		if (type == 's')
			count += point_str(str, amount[0]);
		else if (type == 'd' || type == 'i' || type == 'u' || type == 'x' || type == 'X')
			count += point_num(str, amount[0], prefix);
	}
	else if (ft_strchr(flags[0], 0) && amount[0] != 0)
		count += padding(str, amount[0], ' ', prefix);
	else
	{
		while (str[i])
			i++;
		while (--i >= 0)
			write(1, &str[i], 1);
	}
	return (count);
}

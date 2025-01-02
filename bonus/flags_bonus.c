/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:56:17 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/02 23:56:21 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>
int	minus(char *str, int amount)
{
	int	i;
	int	count;

	i = 0;
	count = amount;
	while (str[i])
		i++;
	if (amount < i)
		count = i;
	amount -= i;
	while (str[--i])
		write(1, &str[i], 1);
	while (amount-- > 0)
		write(1, " ", 1);
	return (count);
}

int	padding(char *str, int amount, char c, char prefix)
{
	int	i;
	int	count;

	i = 0;
	count = amount;
	while (str[i])
		i++;
	while (amount > i)
	{
		write(1, &c, 1);
		amount--;
	}
	if (prefix)
	{
		write(1, &prefix, 1);
		count++;
	}
	while (str[--i])
	{
		write(1, &str[i], 1);
	}
	return (count);
}

int	point_num(char *str, int amount, char prefix)
{
	int	i;
	int	count;

	i = 0;
	count = amount;
	if (prefix)
	{
		write(1, &prefix, 1);
		count++;
	}
	while (str[i])
		i++;
	while (amount >= i)
	{
		write(1, "0", 1);
		amount--;
	}
	while (str[--i])
	{
		write(1, &str[i], 1);
	}
	return (count);
}

int	point_str(char *str, int amount)
{
	int	i;
	int	count;

	i = 0;
	while (str[i])
		i++;
	count = i - amount;
	while (i > amount)
		write(1, &str[--i], 1);
	return (count);
}
/*
void	hash(char *str, int sign)
{
	int	i;
	i = 0;
	
}
*/
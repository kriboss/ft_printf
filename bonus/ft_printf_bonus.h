/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 17:32:10 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/03 17:40:05 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# define TYPE "cspdiuxX%"

# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags
{
	int		minus;
	int		zero;
	int		width;
	int		precision;
	int		star;
	int		type;
}				t_flags;

#endif
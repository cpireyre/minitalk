/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:26:43 by copireyr          #+#    #+#             */
/*   Updated: 2024/04/23 13:38:13 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c);

int	ft_atoi(const char *str)
{
	long	nbr;
	int		sign;

	while (ft_isspace(*str))
		str++;
	sign = (*str != '-') - (*str == '-');
	str += *str == '-' || *str == '+';
	nbr = 0;
	while (ft_isdigit(*str))
	{
		if (nbr > 922337203685477580
			|| (nbr == 922337203685477580
				&& ((sign == 1 && *str >= '7') || (sign == -1 && *str >= '8'))))
			return (-(sign == 1));
		nbr = nbr * 10 + *str++ - '0';
	}
	return (sign * nbr);
}

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ');
}

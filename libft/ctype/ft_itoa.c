/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:27:44 by copireyr          #+#    #+#             */
/*   Updated: 2024/04/15 12:44:19 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	count_digits(unsigned int n);
static char		pop_digit(unsigned int *n);

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	size_t			digits;
	char			*res;
	size_t			size;

	nbr = (unsigned int)(n * (n >= 0) - n * (n < 0));
	digits = count_digits(nbr);
	size = digits + (n < 0);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	if (n < 0)
		res[0] = '-';
	res[size] = '\0';
	while (size != (n < 0))
		res[--size] = pop_digit(&nbr) + '0';
	return (res);
}

static size_t	count_digits(unsigned int n)
{
	size_t	digits;

	digits = 1;
	while (n >= 10)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static char	pop_digit(unsigned int *n)
{
	char	digit;

	digit = *n % 10;
	*n /= 10;
	return (digit);
}

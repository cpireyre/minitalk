/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:31:12 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/03 11:10:59 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"

static size_t	count_digits(uintmax_t n, unsigned char radix);
static char		pop_digit(uintmax_t *n, unsigned char radix);

size_t	ft_ulltoa(uintmax_t n, char *base, char *res)
{
	size_t			digits;
	size_t			ret;
	unsigned char	radix;

	radix = ft_strlen(base);
	digits = count_digits(n, radix);
	ret = digits;
	while (digits)
		res[--digits] = *(pop_digit(&n, radix) + base);
	return (ret);
}

size_t	ft_lltoa(intmax_t n, char *base, char *res)
{
	uintmax_t		nbr;
	size_t			digits;
	size_t			size;
	unsigned char	radix;

	nbr = (uintmax_t)(n * (n >= 0) - n * (n < 0));
	radix = ft_strlen(base);
	digits = count_digits(nbr, radix);
	size = digits;
	while (digits)
		res[--digits] = *(pop_digit(&nbr, radix) + base);
	return (size);
}

static size_t	count_digits(uintmax_t n, unsigned char radix)
{
	size_t	digits;

	digits = 1;
	while (n >= radix)
	{
		n /= radix;
		digits++;
	}
	return (digits);
}

static char	pop_digit(uintmax_t *n, unsigned char radix)
{
	char	digit;

	digit = (char)(*n % radix);
	*n /= radix;
	return (digit);
}

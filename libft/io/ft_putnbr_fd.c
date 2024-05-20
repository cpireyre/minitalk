/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:34:41 by copireyr          #+#    #+#             */
/*   Updated: 2024/04/15 12:39:49 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (n < 0)
		write(fd, "-", 1);
	nbr = (unsigned int)(n * (n > 0) - n * (n < 0));
	if (nbr >= 10)
		ft_putnbr_fd((int)(nbr / 10), fd);
	ft_putchar_fd((int)(nbr % 10 + '0'), fd);
}

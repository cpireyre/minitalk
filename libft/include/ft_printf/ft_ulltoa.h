/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:39:58 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/02 14:41:08 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ULLTOA_H
# define FT_ULLTOA_H

# include <stdint.h>

size_t	ft_ulltoa(uintmax_t n, char *base, char *res);
size_t	ft_lltoa(intmax_t n, char *base, char *res);

#endif

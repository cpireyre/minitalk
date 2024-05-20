/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copireyr <copireyr@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:41:15 by copireyr          #+#    #+#             */
/*   Updated: 2024/05/20 09:41:19 by copireyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!lst)
		return ;
	else if (!*lst)
		*lst = new;
	else
	{
		node = *lst;
		*lst = ft_lstlast(*lst);
		(*lst)->next = new;
		*lst = node;
	}
}

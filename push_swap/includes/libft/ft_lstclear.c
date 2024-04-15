/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:25:06 by apancar           #+#    #+#             */
/*   Updated: 2024/01/29 12:27:14 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prof;

	if (!lst || !(*lst))
		return ;
	while (*lst)
	{
		prof = (*lst)-> next;
		ft_lstdelone(*lst, del);
		*lst = prof;
	}
	*lst = NULL;
}

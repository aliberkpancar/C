/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:52:59 by aliberk           #+#    #+#             */
/*   Updated: 2024/02/06 12:10:14 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*temp_src;

	if (!src || !(*src))
		return ;
	temp_src = *src;
	if ((*src)->next)
		*src = (*src)->next;
	else
		*src = NULL;
	temp_src->next = *dest;
	*dest = temp_src;
}

void	pa(t_stack **dest, t_stack **src)
{
	push(dest, src);
	write (1, "pa\n", 3);
}

void	pb(t_stack **dest, t_stack **src)
{
	push(dest, src);
	write (1, "pb\n", 3);
}

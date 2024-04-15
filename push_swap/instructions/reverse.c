/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:05:36 by apancar           #+#    #+#             */
/*   Updated: 2024/02/06 18:55:25 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse(t_stack **head)
{
	t_stack	*temp;
	t_stack	*iter;

	if (!head || !(*head) || (*head)->next == NULL)
		return ;
	iter = *head;
	while (iter->next->next != NULL)
		iter = iter->next;
	temp = iter->next;
	iter->next = NULL;
	iter = *head;
	*head = temp;
	temp->next = iter;
}

void	rra(t_stack **head)
{
	reverse(head);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **head)
{
	reverse(head);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **heada, t_stack **headb)
{
	reverse(heada);
	reverse(headb);
	write(1, "rrr\n", 4);
}

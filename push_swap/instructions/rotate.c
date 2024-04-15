/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:25:54 by apancar           #+#    #+#             */
/*   Updated: 2024/02/06 20:02:10 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **head)
{
	t_stack	*temp;
	t_stack	*iter;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	temp = *head;
	*head = (*head)->next;
	iter = *head;
	while (iter->next)
		iter = iter->next;
	iter->next = temp;
	temp->next = NULL;
}

void	ra(t_stack **head)
{
	rotate(head);
	write (1, "ra\n", 3);
}

void	rb(t_stack **head)
{
	rotate(head);
	write (1, "rb\n", 3);
}

void	rr(t_stack **heada, t_stack **headb)
{
	rotate(heada);
	rotate(headb);
	write (1, "rr\n", 3);
}

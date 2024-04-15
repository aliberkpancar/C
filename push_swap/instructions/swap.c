/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:02:24 by aliberk           #+#    #+#             */
/*   Updated: 2024/01/29 12:27:14 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack **head)
{
	t_stack	*prof;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	prof = *head;
	*head = (*head)->next;
	prof->next = (*head)->next;
	(*head)->next = prof;
}

void	sa(t_stack **a)
{
	swap(a);
	write (1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	write (1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write (1, "ss\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_settings2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:26:58 by aliberk           #+#    #+#             */
/*   Updated: 2024/02/06 20:04:17 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_node(t_stack **head, long *arr)
{
	t_stack	*temp;
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	if (*head == NULL)
	{
		*head = node;
		node->value = *arr;
		node->next = NULL;
	}
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = node;
		node->value = *arr;
		node->next = NULL;
	}
}

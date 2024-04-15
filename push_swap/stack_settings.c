/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:44:05 by apancar           #+#    #+#             */
/*   Updated: 2024/02/07 09:13:28 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len(t_stack **head)
{
	t_stack	*prof;
	int		i;

	i = 0;
	if (!head)
		return (0);
	prof = *head;
	while (prof != NULL)
	{
		prof = prof->next;
		i++;
	}
	return (i);
}

int	check_sorted(t_stack **head)
{
	t_stack	*prof;

	if (head == NULL || *head == NULL)
		return (1);
	prof = *head;
	if (prof->next == NULL)
		return (1);
	while (prof->next != NULL)
	{
		if (prof->value > prof->next->value)
			return (1);
		else
			prof = prof->next;
	}
	return (0);
}

int	check_duplicate(t_stack **head)
{
	t_stack	*prof;
	t_stack	*profy;

	if (head == NULL || *head == NULL)
		return (0);
	prof = *head;
	while (prof != NULL)
	{
		profy = prof->next;
		while (profy != NULL)
		{
			if (prof->value == profy->value)
				return (0);
			profy = profy->next;
		}
		prof = prof->next;
	}
	return (1);
}

t_stack	*max_node(t_stack **head)
{
	t_stack	*temp;
	t_stack	*max;

	temp = *head;
	max = NULL;
	if (*head == NULL)
		return (NULL);
	max = *head;
	while (temp != NULL)
	{
		if (temp != NULL && max->value < temp->value)
			max = temp;
		temp = temp->next;
	}
	return (max);
}

t_stack	*min_node(t_stack **head)
{
	t_stack	*temp;
	t_stack	*min;

	if (!head || !(*head))
		return (NULL);
	temp = *head;
	min = NULL;
	min = *head;
	while (temp != NULL)
	{
		if (min->value > temp->value)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

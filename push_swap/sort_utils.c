/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 07:34:54 by apancar           #+#    #+#             */
/*   Updated: 2024/02/07 08:43:50 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include "./includes/libft/libft.h"

int	index_of(t_stack **head, int no)
{
	t_stack	*temp;
	int		i;

	temp = *head;
	i = 0;
	while (temp != NULL)
	{
		if (no == temp->value)
			return (i);
		temp = temp->next;
		i++;
	}
	return (-1);
}

static int	find_minsmax(t_stack **head, int no)
{
	t_stack	*temp;
	int		minsmax;
	int		i;
	int		j;

	minsmax = INT_MIN;
	temp = *head;
	i = 0;
	j = 0;
	while (temp != NULL)
	{
		if (temp->value > minsmax && temp->value < no)
		{
			minsmax = temp->value;
			j = i;
		}
		temp = temp->next;
		i++;
	}
	return (j);
}

int	index_of_mins_max(t_stack **head, int no)
{
	t_stack	*temp;
	int		minsmax;
	int		j;
	int		i;

	temp = *head;
	(*head)->t_maxdex = max_node(head);
	(*head)->t_mindex = min_node(head);
	minsmax = INT32_MIN;
	i = 0;
	if (no > (*head)->t_maxdex->value || no < (*head)->t_mindex->value)
	{
		i = index_of(head, (*head)->t_maxdex->value);
		if (i == -1)
			return (-1);
		return (i);
	}
	else
	{
		j = 0;
		j = find_minsmax(head, no);
		return (j);
	}
}

static int	find_maxsmin(t_stack **head, int no)
{
	t_stack	*temp;
	int		maxsmin;
	int		i;
	int		j;

	maxsmin = INT32_MAX;
	temp = *head;
	(*head)->t_maxdex = max_node(head);
	(*head)->t_mindex = min_node(head);
	j = 0;
	i = 0;
	while (temp != NULL)
	{
		if (temp->value < maxsmin && temp->value > no)
		{
			maxsmin = temp->value;
			j = i;
		}
		temp = temp->next;
		i++;
	}
	return (j);
}

int	index_of_maxs_min(t_stack **head, int no)
{
	t_stack	*temp;
	int		maxsmin;
	int		i;
	int		j;

	maxsmin = INT_MAX;
	temp = *head;
	(*head)->t_maxdex = max_node(head);
	(*head)->t_mindex = min_node(head);
	if ((*head)->t_maxdex == NULL || (*head)->t_mindex == NULL)
		return (-1);
	i = 0;
	if ((no > (*head)->t_maxdex->value) || (no < (*head)->t_mindex->value))
	{
		i = index_of(head, (*head)->t_mindex->value);
		if (i == -1)
			return (-1);
		return (i);
	}
	else
	{
		j = 0;
		j = find_maxsmin(head, no);
		return (j);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:10:52 by aliberk           #+#    #+#             */
/*   Updated: 2024/02/07 08:47:00 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./includes/libft/libft.h"

void	sort_3(t_stack	**a)
{
	t_stack	*max;
	t_stack	*temp;
	t_stack	*temp2;

	temp = *a;
	temp2 = temp->next;
	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	max = max_node(a);
	if (temp->value == max->value)
		ra(a);
	if (temp2->value == max->value)
		rra(a);
	if (check_sorted(a))
		sa(a);
}

static void	sort_4(t_stack **heada, t_stack **headb)
{
	t_stack	*temp;
	t_stack	*min;

	min = min_node(heada);
	temp = *heada;
	while (temp != NULL && temp->value != min->value)
	{
		ra(heada);
		temp = *heada;
	}
	pb(headb, heada);
	sort_3(heada);
	pa(heada, headb);
}

static void	sort_upper_5(t_stack **heada, t_stack **headb)
{
	pb(headb, heada);
	pb(headb, heada);
	if (!check_sorted(headb))
		sb(headb);
}

void	a_sort(t_stack **heada, t_stack **headb)
{
	int		lena;
	t_stack	*temp;

	temp = *heada;
	lena = ft_len(heada);
	if (lena == 4)
		sort_4(heada, headb);
	if (lena >= 5)
	{
		sort_upper_5(heada, headb);
		lena -= 2;
	}
	if (lena > 3)
	{
		while (lena > 3)
		{
			sort_upper_3(heada, headb);
			lena--;
		}
	}
	if (lena == 3)
		sort_3(heada);
	if (lena == 2 && check_sorted(heada))
		sa(heada);
}

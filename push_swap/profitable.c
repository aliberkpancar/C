/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   profitable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 07:03:16 by apancar           #+#    #+#             */
/*   Updated: 2024/02/07 10:42:37 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

t_stack	*find_profitable(t_stack **heada, t_stack **headb)
{
	t_stack	*best_prof;
	t_stack	*p;
	t_stack	*temp;

	(*headb)->best = INT_MAX;
	p = malloc(sizeof(t_stack));
	if (!p)
		return (NULL);
	temp = *heada;
	best_prof = NULL;
	while (temp && (calculate_price(heada, headb, p, temp->value), 1))
	{
		if (p->price < (*headb)->best)
		{
			(*headb)->best = p->price;
			if (best_prof)
				free (best_prof);
			best_prof = malloc(sizeof(t_stack));
			if (!best_prof)
				return (free (best_prof), NULL);
			*best_prof = *p;
		}
		temp = temp->next;
	}
	return (free (p), best_prof);
}

t_stack	*find_profitable_r(t_stack **heada, t_stack **headb)
{
	t_stack	*best_prof_r;
	t_stack	*p_r;
	t_stack	*temp;

	(*heada)->best = INT_MAX;
	p_r = malloc(sizeof(t_stack));
	if (!p_r)
		return (NULL);
	temp = *headb;
	best_prof_r = NULL;
	while (temp && (calculate_price_r(heada, headb, p_r, temp->value), 1))
	{
		if (p_r->price < (*heada)->best)
		{
			(*heada)->best = p_r->price;
			if (best_prof_r)
				free (best_prof_r);
			best_prof_r = malloc(sizeof(t_stack));
			if (!best_prof_r)
				return (NULL);
			*best_prof_r = *p_r;
		}
		temp = temp->next;
	}
	return (free (p_r), best_prof_r);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:37:24 by aliberk           #+#    #+#             */
/*   Updated: 2024/02/05 15:37:39 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_one(t_stack **heada, t_stack **headb, t_stack *prof)
{
	int		var;

	if (!heada || !headb || !prof)
		return ;
	var = prof->index - prof->mindex;
	while (prof->mindex > 0)
	{
		rr(heada, headb);
		prof->mindex--;
	}
	while (var > 0)
	{
		ra(heada);
		var--;
	}
	pb(headb, heada);
}

void	case_two(t_stack **heada, t_stack **headb, t_stack *prof)
{
	int		var;

	if (!heada || !headb || !prof)
		return ;
	var = prof->mindex - prof->index;
	while (prof->index > 0)
	{
		rr(heada, headb);
		prof->index--;
	}
	while (var > 0)
	{
		rb(headb);
		var--;
	}
	pb(headb, heada);
}

void	case_three(t_stack **heada, t_stack **headb, t_stack *prof)
{
	int		var;

	if (!heada || !headb || !prof)
		return ;
	var = prof->index - prof->mindex;
	while (prof->mindex + 1 > 0)
	{
		rrr(heada, headb);
		prof->mindex--;
	}
	while (var > 0)
	{
		rra(heada);
		var--;
	}
	pb(headb, heada);
}

void	case_four(t_stack **heada, t_stack **headb, t_stack *prof)
{
	int		var;

	if (!heada || !headb || !prof)
		return ;
	var = prof->mindex - prof->index;
	while (prof->index + 1 > 0)
	{
		rrr(heada, headb);
		prof->index--;
	}
	while (var > 0)
	{
		rrb(headb);
		var--;
	}
	pb(headb, heada);
}

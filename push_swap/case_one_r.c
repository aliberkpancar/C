/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_one_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 07:35:37 by apancar           #+#    #+#             */
/*   Updated: 2024/02/06 13:43:52 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_one_r(t_stack **heada, t_stack **headb, t_stack *prof_r)
{
	int		var;

	if (!heada || !headb || !prof_r)
		return ;
	var = prof_r->index - prof_r->mindex;
	while (prof_r->mindex > 0)
	{
		rr(heada, headb);
		prof_r->mindex--;
	}
	while (var > 0)
	{
		rb(heada);
		var--;
	}
	pa(heada, headb);
}

void	case_two_r(t_stack **heada, t_stack **headb, t_stack *prof_r)
{
	int		var;

	if (!heada || !headb || !prof_r)
		return ;
	var = prof_r->mindex - prof_r->index;
	while (prof_r->index > 0)
	{
		rr(heada, headb);
		prof_r->index--;
	}
	while (var > 0)
	{
		ra(heada);
		var--;
	}
	pa(heada, headb);
}

void	case_three_r(t_stack **heada, t_stack **headb, t_stack *prof_r)
{
	int		var;

	if (!heada || !headb || !prof_r)
		return ;
	var = prof_r->index - prof_r->mindex;
	while (prof_r->mindex + 1 > 0)
	{
		rrr(heada, headb);
		prof_r->mindex--;
	}
	while (var > 0)
	{
		rrb(headb);
		var--;
	}
	pa(heada, headb);
}

void	case_four_r(t_stack **heada, t_stack **headb, t_stack *prof_r)
{
	int		var;

	if (!heada || !headb || !prof_r)
		return ;
	var = prof_r->mindex - prof_r->index;
	while (prof_r->index + 1 > 0)
	{
		rrr(heada, headb);
		prof_r->index--;
	}
	while (var > 0)
	{
		rra(heada);
		var--;
	}
	pa(heada, headb);
}

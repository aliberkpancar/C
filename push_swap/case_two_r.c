/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_two_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 07:36:21 by apancar           #+#    #+#             */
/*   Updated: 2024/02/05 08:29:26 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_five_one_r(t_stack **heada, t_stack **headb, t_stack *prof_r)
{
	if (!heada || !headb || !prof_r)
		return ;
	while (prof_r->index + 1 > 0)
	{
		rrb(headb);
		prof_r->index--;
	}
	while (prof_r->mindex > 0)
	{
		ra(heada);
		prof_r->mindex--;
	}
	pa(heada, headb);
}

void	case_five_two_r(t_stack **heada, t_stack **headb, t_stack *prof_r)
{
	if (!heada || !headb || !prof_r)
		return ;
	while (prof_r->mindex + 1 > 0)
	{
		rra(heada);
		prof_r->mindex--;
	}
	while (prof_r->index > 0)
	{
		rb(headb);
		prof_r->index--;
	}
	pa(heada, headb);
}

void	case_five_three_r(t_stack **heada, t_stack **headb, t_stack *prof_r)
{
	if (!heada || !headb || !prof_r)
		return ;
	if (prof_r->index == prof_r->temp_index && prof_r->mindex \
	== prof_r->temp_mindex)
	{
		while (prof_r->mindex > 0)
		{
			rr(heada, headb);
			prof_r->mindex--;
		}
		pa(heada, headb);
	}
	else if (prof_r->index != prof_r->temp_index && prof_r->mindex \
	!= prof_r->temp_mindex)
	{
		while (prof_r->mindex + 1 > 0)
		{
			rrr(heada, headb);
			prof_r->mindex--;
		}
		pa(heada, headb);
	}
}

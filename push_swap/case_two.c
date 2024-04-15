/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:27:09 by aliberk           #+#    #+#             */
/*   Updated: 2024/02/04 10:59:58 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_five_one(t_stack **heada, t_stack **headb, t_stack *prof)
{
	if (!heada || !headb || !prof)
		return ;
	while (prof->index + 1 > 0)
	{
		rra(heada);
		prof->index--;
	}
	while (prof->mindex > 0)
	{
		rb(headb);
		prof->mindex--;
	}
	pb(headb, heada);
}

void	case_five_two(t_stack **heada, t_stack **headb, t_stack *prof)
{
	if (!heada || !headb || !prof)
		return ;
	while (prof->mindex + 1 > 0)
	{
		rrb(headb);
		prof->mindex--;
	}
	while (prof->index > 0)
	{
		ra(heada);
		prof->index--;
	}
	pb(headb, heada);
}

void	case_five_three(t_stack **heada, t_stack **headb, t_stack *prof)
{
	if (!heada || !headb || !prof)
		return ;
	if (prof->index == prof->temp_index && prof->mindex \
	== prof->temp_mindex)
	{
		while (prof->mindex > 0)
		{
			rr(heada, headb);
			prof->mindex--;
		}
		pb(headb, heada);
	}
	else if (prof->index != prof->temp_index && prof->mindex \
	!= prof->temp_mindex)
	{
		while (prof->mindex + 1 > 0)
		{
			rrr(heada, headb);
			prof->mindex--;
		}
		pb(headb, heada);
	}
}

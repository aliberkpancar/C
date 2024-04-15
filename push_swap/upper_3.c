/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 07:55:28 by aliberk           #+#    #+#             */
/*   Updated: 2024/02/07 10:36:34 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_five(t_stack **heada, t_stack **headb, t_stack *prof)
{
	if (!heada || !headb)
		return ;
	if (prof->index != prof->temp_index \
	&& prof->temp_mindex == prof->mindex)
		case_five_one(heada, headb, prof);
	else if (prof->mindex != prof->temp_mindex \
	&& prof->index == prof->temp_index)
		case_five_two(heada, headb, prof);
	else if (prof->index == prof->mindex)
		case_five_three(heada, headb, prof);
}

void	case_five_r(t_stack **heada, t_stack **headb, t_stack *prof_r)
{
	if (!heada || !headb || !prof_r)
		return ;
	if (prof_r->index != prof_r->temp_index \
	&& prof_r->temp_mindex == prof_r->mindex)
		case_five_one_r(heada, headb, prof_r);
	else if (prof_r->mindex != prof_r->temp_mindex \
	&& prof_r->index == prof_r->temp_index)
		case_five_two_r(heada, headb, prof_r);
	else if (prof_r->index == prof_r->mindex)
		case_five_three_r(heada, headb, prof_r);
}

void	b_sort(t_stack **heada, t_stack **headb)
{
	int	len;

	len = ft_len(headb);
	if (len == 1)
		pa(heada, headb);
	if (len == 2 && !check_sorted(headb))
		sb(headb);
	while (len > 0)
	{
		p_sort(heada, headb);
		len--;
	}
}

void	sort_upper_3(t_stack **heada, t_stack **headb)
{
	t_stack	*prof;

	if (!heada || !(*heada) || !headb || !(*headb))
		return ;
	prof = find_profitable(heada, headb);
	if (!prof)
		return ;
	if (prof->temp_index >= prof->temp_mindex && prof->index == \
	prof->temp_index && prof->mindex == prof->temp_mindex)
		case_one(heada, headb, prof);
	else if (prof->temp_index < prof->temp_mindex && prof->index \
	== prof->temp_index && prof->mindex == prof->temp_mindex)
		case_two(heada, headb, prof);
	else if (prof->index >= prof->mindex && prof->index != \
	prof->temp_index && prof->mindex != prof->temp_mindex)
		case_three(heada, headb, prof);
	else if (prof->index < prof->mindex && prof->index != \
	prof->temp_index && prof->mindex != prof->temp_mindex)
		case_four(heada, headb, prof);
	else
		case_five(heada, headb, prof);
	free (prof);
}

void	p_sort(t_stack **heada, t_stack **headb)
{
	t_stack	*prof_r;

	if (!heada || !(*heada) || !headb || !(*headb))
		return ;
	prof_r = find_profitable_r(heada, headb);
	if (prof_r == NULL)
		return ;
	if (prof_r->temp_index >= prof_r->temp_mindex && prof_r->index \
	== prof_r->temp_index && prof_r->mindex == prof_r->temp_mindex)
		case_one_r(heada, headb, prof_r);
	else if (prof_r->temp_index < prof_r->temp_mindex && prof_r->index \
	== prof_r->temp_index && prof_r->mindex == prof_r->temp_mindex)
		case_two_r(heada, headb, prof_r);
	else if (prof_r->index >= prof_r->mindex && prof_r->index != \
	prof_r->temp_index && prof_r->mindex != prof_r->temp_mindex)
		case_three_r(heada, headb, prof_r);
	else if (prof_r->index < prof_r->mindex && prof_r->index != \
	prof_r->temp_index && prof_r->mindex != prof_r->temp_mindex)
		case_four_r(heada, headb, prof_r);
	else
		case_five_r(heada, headb, prof_r);
	free (prof_r);
}

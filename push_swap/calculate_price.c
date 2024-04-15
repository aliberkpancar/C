/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_price.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 07:05:06 by apancar           #+#    #+#             */
/*   Updated: 2024/02/07 10:31:20 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_price(t_stack **heada, t_stack **headb, t_stack *p, int no)
{
	int	lena;
	int	lenb;

	lena = ft_len(heada);
	lenb = ft_len(headb);
	p->temp_index = index_of(heada, no);
	if (p->temp_index == -1)
		return ;
	p->value = no;
	if (lena <= p->temp_index * 2)
		p->index = lena - 1 - p->temp_index;
	else
		p->index = p->temp_index;
	p->temp_mindex = index_of_mins_max(headb, no);
	if (p->temp_mindex == -1)
		return ;
	if (lenb <= p->temp_mindex * 2)
		p->mindex = lenb - 1 - p->temp_mindex;
	else
		p->mindex = p->temp_mindex;
	p->price = p->index + p->mindex;
}

void	calculate_price_r(t_stack **heada, t_stack **headb, \
t_stack *p_r, int no)
{
	int	lena;
	int	lenb;

	lena = ft_len(heada);
	lenb = ft_len(headb);
	p_r->value = no;
	p_r->temp_index = index_of(headb, no);
	if (p_r->temp_index == -1)
		return ;
	if (lenb <= p_r->temp_index * 2)
		p_r->index = lenb - 1 - p_r->temp_index;
	else
		p_r->index = p_r->temp_index;
	p_r->temp_mindex = index_of_maxs_min(heada, no);
	if (p_r->temp_mindex == -1)
		return ;
	if (lena <= p_r->temp_mindex * 2)
		p_r->mindex = lena - 1 - p_r->temp_mindex;
	else
		p_r->mindex = p_r->temp_mindex;
	p_r->price = p_r->index + p_r->mindex;
}

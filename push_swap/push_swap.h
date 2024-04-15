/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:33:06 by aliberk           #+#    #+#             */
/*   Updated: 2024/02/07 10:49:47 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				len;
	int				temp_index;
	int				temp_mindex;
	int				index;
	int				mindex;
	int				price;
	int				best;
	struct s_stack	*t_maxdex;
	struct s_stack	*t_mindex;
	struct s_stack	*next;
}					t_stack;
//instructions
void	pa(t_stack **dest, t_stack **src);
void	pb(t_stack **dest, t_stack **src);
void	rra(t_stack **head);
void	rrb(t_stack **head);
void	rrr(t_stack **head, t_stack **heady);
void	ra(t_stack **head);
void	rb(t_stack **head);
void	rr(t_stack **heada, t_stack **headb);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
//stack_settings
int		ft_len(t_stack **head);
t_stack	*max_node(t_stack **head);
t_stack	*min_node(t_stack **head);
int		check_sorted(t_stack **head);
int		check_duplicate(t_stack **head);
void	ft_add_node(t_stack **head, long *arr);
//sorting
void	a_sort(t_stack	**head, t_stack	**heady);
void	b_sort(t_stack **heada, t_stack **headb);
void	p_sort(t_stack **heada, t_stack **headb);
void	sort_3(t_stack	**a);
void	sort_upper_3(t_stack **heada, t_stack **headb);
void	case_one(t_stack **heada, t_stack **headb, t_stack *prof);
void	case_two(t_stack **heada, t_stack **headb, t_stack *prof);
void	case_three(t_stack **heada, t_stack **headb, t_stack *prof);
void	case_four(t_stack **heada, t_stack **headb, t_stack *prof);
void	case_five(t_stack **heada, t_stack **headb, t_stack *prof);
void	case_five_one(t_stack **heada, t_stack **headb, t_stack *prof);
void	case_five_two(t_stack **heada, t_stack **headb, t_stack *prof);
void	case_five_three(t_stack **heada, t_stack **headb, t_stack *prof);
void	case_one_r(t_stack **heada, t_stack **headb, t_stack *prof);
void	case_two_r(t_stack **heada, t_stack **headb, t_stack *prof);
void	case_three_r(t_stack **heada, t_stack **headb, t_stack *prof);
void	case_four_r(t_stack **heada, t_stack **headb, t_stack *prof);
void	case_five_r(t_stack **heada, t_stack **headb, t_stack *prof);
void	case_five_one_r(t_stack **heada, t_stack **headb, t_stack *prof);
void	case_five_two_r(t_stack **heada, t_stack **headb, t_stack *prof);
void	case_five_three_r(t_stack **heada, t_stack **headb, t_stack *prof);
//sorting_utils
t_stack	*find_profitable(t_stack **heada, t_stack **headb);
t_stack	*find_profitable_r(t_stack **heada, t_stack **headb);
int		index_of(t_stack **head, int no);
int		index_of_mins_max(t_stack **head, int no);
int		index_of_maxs_min(t_stack **head, int no);
void	calculate_price(t_stack **heada, t_stack **headb, t_stack *p, int no);
void	calculate_price_r(t_stack **heada, t_stack **headb, t_stack *p, int no);
//utils
long	ft_atol(const char *str);
int		max_index(t_stack **head);
int		check_arg(char **args);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:26:55 by aliberk           #+#    #+#             */
/*   Updated: 2024/02/07 10:18:32 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./includes/libft/libft.h"

static void	add_args_to_stack(t_stack **head, char *av[])
{
	long	*arr;
	char	**args;
	int		i;

	args = ft_split(av[1], ' ');
	if (!args)
		return ;
	arr = malloc(sizeof(long) * 520);
	if (!arr)
		return ;
	i = 0;
	while (args[i] != NULL)
	{
		if (check_arg(&args[i]))
		{
			write (2, "Error\n", 6);
			exit (1);
		}
		arr[i] = ft_atol(args[i]);
		ft_add_node(head, &arr[i]);
		i++;
	}
	free(args);
	free(arr);
}

static void	add_args_to_stack_2(t_stack **head, int ac, char *av[])
{
	long	*arr;
	int		i;

	arr = malloc(sizeof(long) * (ac - 1));
	if (!arr)
		return ;
	i = 0;
	while (av[i + 1])
	{
		if (check_arg(&av[i + 1]))
		{
			write (2, "Error\n", 6);
			free (arr);
			exit (1);
		}
		arr[i] = ft_atol(av[i + 1]);
		ft_add_node(head, &arr[i]);
		i++;
	}
	free (arr);
}

static void	last_sort(t_stack **heada)
{
	t_stack	*mindex;
	int		i;
	int		len;

	len = ft_len(heada);
	i = 0;
	mindex = min_node(heada);
	i = index_of(heada, mindex->value);
	if (i * 2 < len)
	{
		while (i > 0)
		{
			ra(heada);
			i--;
		}
	}
	else
	{
		while (i < len)
		{
			rra(heada);
			i++;
		}
	}
}

void	free_a(t_stack **head)
{
	t_stack	*temp;

	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && av[1][0] == '\0'))
		exit (1);
	else if (ac == 2)
		add_args_to_stack(&a, av);
	else
		add_args_to_stack_2(&a, ac, av);
	if (!check_duplicate(&a))
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	if (check_sorted(&a))
	{
		a_sort(&a, &b);
		b_sort(&a, &b);
		last_sort(&a);
	}
	free_a(&a);
	return (0);
}

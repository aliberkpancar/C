/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:01:20 by aliberk           #+#    #+#             */
/*   Updated: 2024/02/07 09:09:55 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./includes/libft/libft.h"
#include <limits.h>

int	check_arg(char **args)
{
	int	i;
	int	j;

	i = -1;
	while (args[++i])
	{
		j = 0;
		if (!((args[i][j] >= '0' && args[i][j] <= '9') || \
			(args[i][j] == '-') || (args[i][j] == '+')))
			return (1);
		while (args[i][++j])
		{
			if (!((args[i][j] >= '0' && args[i][j] <= '9')))
				return (1);
		}
	}
	return (0);
}

long	ft_atol(const char *str)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	if (result > INT_MAX || result < INT_MIN)
	{
		write (2, "Error\n", 6);
		exit (1);
	}
	return (result * sign);
}

int	max_index(t_stack **head)
{
	t_stack	*prof;
	int		maxdex;
	int		i;

	prof = *head;
	maxdex = INT_MIN;
	i = 0;
	while (prof->next != NULL)
	{
		if (maxdex < prof->value)
			maxdex = i;
		prof = prof->next;
		i++;
	}
	return (maxdex);
}

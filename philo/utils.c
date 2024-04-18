/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 07:36:19 by apancar           #+#    #+#             */
/*   Updated: 2024/04/05 08:03:16 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	msg(char *error_message)
{
	printf("%s\n", error_message);
	return (1);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

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
	return (result * sign);
}

unsigned long	ft_get_timeo(t_sim *sim)
{
	gettimeofday(&sim->time, NULL);
	return (((sim->time.tv_usec / 1000) \
	+ (sim->time.tv_sec * 1000)) - sim->start);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bon_appetite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 06:11:27 by apancar           #+#    #+#             */
/*   Updated: 2024/04/18 06:20:20 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_philo *phi, unsigned long time)
{
	unsigned long	a_time;

	a_time = ft_get_timeo(phi->sim) + time;
	while (ft_get_timeo(phi->sim) < a_time)
		if (usleep(100) != 0)
			return ;
}

void	*bon_appetite(void *arg)
{
	t_philo	*phi;

	if (!arg)
		return (NULL);
	phi = (t_philo *)arg;
	pthread_detach(*phi->thread);
	while (1)
	{
		if (phi->id % 2 == 1)
			usleep(100);
		eat(phi);
		sleep_(phi);
		think(phi);
	}
	return (NULL);
}

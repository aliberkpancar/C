/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_eat_sleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 07:37:39 by apancar           #+#    #+#             */
/*   Updated: 2024/04/18 06:20:03 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat_count(t_philo *phi)
{
	pthread_mutex_lock(phi->sim->meal_count);
	phi->eat_count++;
	phi->sim->sim_eat_count++;
	pthread_mutex_unlock(phi->sim->meal_count);
}

void	eat(t_philo *phi)
{
	pthread_mutex_lock(&phi->sim->c_s[phi->id]);
	pthread_mutex_lock(phi->sim->print);
	printf("%lu %d has taken a fork\n", ft_get_timeo(phi->sim), phi->id + 1);
	pthread_mutex_unlock(phi->sim->print);
	pthread_mutex_lock(&phi->sim->c_s[(phi->id + 1) % phi->sim->num_of_phi]);
	pthread_mutex_lock(phi->sim->print);
	printf("%lu %d has taken a fork\n", ft_get_timeo(phi->sim), phi->id + 1);
	printf("%lu %d is eating\n", ft_get_timeo(phi->sim), phi->id + 1);
	pthread_mutex_unlock(phi->sim->print);
	ft_sleep(phi, phi->sim->time2eat);
	pthread_mutex_unlock(&phi->sim->c_s[phi->id]);
	pthread_mutex_unlock(&phi->sim->c_s[(phi->id + 1) % phi->sim->num_of_phi]);
	pthread_mutex_lock(phi->sim->meal_count);
	phi->last_eat_time = ft_get_timeo(phi->sim);
	pthread_mutex_unlock(phi->sim->meal_count);
	eat_count(phi);
}

void	sleep_(t_philo *phi)
{
	pthread_mutex_lock(phi->sim->print);
	printf("%lu %d is sleeping\n", ft_get_timeo(phi->sim), (phi->id + 1));
	pthread_mutex_unlock(phi->sim->print);
	ft_sleep(phi, phi->sim->time2sleep);
}

void	think(t_philo *phi)
{
	pthread_mutex_lock(phi->sim->print);
	printf("%lu %d is thinking\n", ft_get_timeo(phi->sim), (phi->id + 1));
	pthread_mutex_unlock(phi->sim->print);
}

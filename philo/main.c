/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 13:34:11 by apancar           #+#    #+#             */
/*   Updated: 2024/04/18 06:14:36 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_sim	*sim;

	sim = NULL;
	if (ac != 6 && ac != 5)
		return (msg("Invalid arguments."), 1);
	else
		if (init_sim(sim, av) != 0)
			return (1);
	return (0);
}

static void	dispose(t_sim *sim)
{
	int	i;

	free(sim->meal_count);
	free(sim->print);
	free(sim->c_s);
	i = 0;
	while (i < sim->num_of_phi)
	{
		free(sim->phi[i].thread);
		i++;
	}
	free(sim->phi);
	free(sim);
}

int	thread_control(t_sim *sim)
{
	int	i;

	i = 0;
	pthread_mutex_lock(sim->meal_count);
	while (i < sim->num_of_phi)
	{
		if (sim->phi[i].must_eat != -1 && sim->phi[i].must_eat * \
		sim->num_of_phi <= sim->sim_eat_count)
		{
			pthread_mutex_unlock(sim->meal_count);
			return (dispose(sim), 1);
		}
		if (ft_get_timeo(sim) - (unsigned long)sim->phi[i].last_eat_time > \
		(unsigned long)sim->time2die)
		{
			pthread_mutex_lock(sim->print);
			printf("%d is dead\n", sim->phi->id + 1);
			pthread_mutex_unlock(sim->print);
			pthread_mutex_unlock(sim->meal_count);
			return (dispose(sim), 1);
		}
		i++;
	}
	pthread_mutex_unlock(sim->meal_count);
	return (0);
}

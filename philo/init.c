/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apancar <apancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:18:21 by apancar           #+#    #+#             */
/*   Updated: 2024/04/18 06:19:32 by apancar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	allocate(t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->num_of_phi)
	{
		sim->phi[i].thread = (pthread_t *)malloc(sizeof(pthread_t));
		if (!sim->phi[i].thread)
			return (free(sim->phi[i].thread), 1);
		i++;
	}
	sim->c_s = (pthread_mutex_t *)
		malloc(sizeof(pthread_mutex_t) * (sim->num_of_phi));
	if (!sim->c_s)
		return (free(sim->c_s), 1);
	sim->print = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!sim->print)
		return (free(sim->print), 1);
	sim->meal_count = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!sim->meal_count)
		return (free(sim->meal_count), 1);
	return (0);
}

int	init_philos(t_sim *sim)
{
	int	i;

	if (allocate(sim) != 0)
		return (free(sim), 1);
	i = -1;
	while (++i < sim->num_of_phi)
	{
		sim->phi[i].id = i;
		sim->phi[i].eat_count = 0;
		sim->phi[i].last_eat_time = 0;
		sim->phi[i].sim = sim;
		pthread_mutex_init(&(sim->c_s[i]), NULL);
	}
	pthread_mutex_init(sim->print, NULL);
	pthread_mutex_init(sim->meal_count, NULL);
	sim->start = ft_get_timeo(sim);
	i = -1;
	while (++i < sim->num_of_phi)
		if (pthread_create(sim->phi[i].thread, NULL, \
		&bon_appetite, &(sim->phi[i])) != 0)
			return (free (sim->phi[i].thread), 1);
	while (1)
		if (thread_control(sim) != 0)
			return (1);
}

static void	init_init_sim(t_sim *sim, char *av[])
{
	sim->start = 0;
	sim->sim_eat_count = 0;
	sim->time2die = ft_atoi(av[2]);
	sim->time2eat = ft_atoi(av[3]);
	sim->time2sleep = ft_atoi(av[4]);
}

int	init_sim(t_sim *sim, char *av[])
{
	int	i;

	i = -1;
	sim = (t_sim *)malloc(sizeof(t_sim));
	if (!sim)
		return (free (sim), 1);
	sim->num_of_phi = ft_atoi(av[1]);
	if (sim->num_of_phi < 1 || sim->num_of_phi > 200)
		return (free (sim), msg("Invalid number of philosopers"), 1);
	sim->phi = malloc(sizeof(t_philo) * (sim->num_of_phi));
	if (!sim->phi)
		return (free (sim->phi), 1);
	init_init_sim(sim, av);
	if (sim->time2die < 60 || sim->time2eat < 60 || sim->time2sleep < 60)
		return (1);
	while (++i < sim->num_of_phi)
	{
		if (av[5])
			sim->phi[i].must_eat = ft_atoi(av[5]);
		else
			sim->phi[i].must_eat = -1;
	}
	if (init_philos(sim) != 0)
		return (1);
	return (0);
}

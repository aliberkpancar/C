/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliberk <aliberk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 08:09:24 by apancar           #+#    #+#             */
/*   Updated: 2024/04/09 17:57:02 by aliberk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>

struct	s_sim;

typedef struct s_philo
{
	int					id;
	int					must_eat;
	int					eat_count;
	long				last_eat_time;
	pthread_t			*thread;
	struct s_sim		*sim;
}						t_philo;

typedef struct s_sim
{
	int					sim_eat_count;
	int					num_of_phi;
	long				time2sleep;
	long				start;
	long				time2die;
	long				time2eat;
	struct timeval		time;
	pthread_mutex_t		*print;
	pthread_mutex_t		*meal_count;
	pthread_mutex_t		*c_s;
	t_philo				*phi;
}						t_sim;

//error_handles
int				msg(char *error_message);
//utils
unsigned long	ft_get_timeo(t_sim *sim);
int				ft_atoi(const char *str);
//init
int				allocate(t_sim *t_sim);
int				init_philos(t_sim *sim);
int				init_sim(t_sim *sim, char *av[]);
//main functions
int				thread_control(t_sim *sim);
void			*bon_appetite(void *arg);
void			eat_count(t_philo *phi);
void			eat(t_philo *phi);
void			sleep_(t_philo *phi);
void			think(t_philo *phi);
void			ft_sleep(t_philo *phi, unsigned long time);

#endif
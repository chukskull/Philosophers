/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:36:20 by snagat            #+#    #+#             */
/*   Updated: 2022/04/07 02:37:51 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct g_rules
{
	int					philos_fork;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_time_eat;
	struct timeval		simulations;
	unsigned long		cur_time;
	int					dead;
}	t_rules;

typedef struct s_philo
{
	int				id;
	int				sleeping;
	t_rules			*rules;
	pthread_t		thread;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	protect;
	unsigned long	last_m;
	int				count;
}	t_philo;

void	ft_usleep(int time);
void	*g_rules(void *philo);
int		eat(t_philo *philo, t_rules *rl);

#endif
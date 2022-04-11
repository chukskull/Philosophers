/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_rules_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:16:35 by snagat            #+#    #+#             */
/*   Updated: 2022/04/11 10:24:58 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

void	*check(void *input)
{
	t_philo			*philo;
	int				i;
	unsigned long	time;

	philo = (t_philo *)input;
	i = 0;
	while (1)
	{
		usleep(300);
		time = get_time();
		if (time >= philo->last_m + philo->rules->time_to_die)
			exit(0);
	}
}

void	g_bonus_rules(t_philo *philo, t_vars *vars)
{
	pthread_create(vars->check, NULL, check, philo);
	while (1)
	{
		if (philo->rules->number_of_time_eat == philo->count)
			exit(1);
		sem_wait(vars->sem);
		ft_printf("has taken a fork", philo, vars);
		sem_wait(vars->sem);
		ft_printf("has taken a fork", philo, vars);
		ft_printf("is eating", philo, vars);
		philo->last_m = get_time();
		philo->count++;
		ft_usleep(philo->rules->time_to_eat);
		sem_post(vars->sem);
		sem_post(vars->sem);
		ft_printf("is sleeping", philo, vars);
		ft_usleep(philo->rules->time_to_sleep);
		ft_printf("is thinking", philo, vars);
	}
}

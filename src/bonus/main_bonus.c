/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 06:42:29 by snagat            #+#    #+#             */
/*   Updated: 2022/04/10 23:43:24 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <signal.h>

void ft_kill(t_philo *philo)
{
	int i;

	i = 0;
	while (i < philo->rules->philos_fork)
	{
		kill(philo[i].pid, SIGKILL);
		i++;
	}
	exit(0);
}

void *check(void *input)
{
	t_philo *philo;
	int i;
	unsigned long time;

	philo = (t_philo *)input;
	i = 0;
	while (1)
	{
		usleep(100);
		time = get_time();
		if (time >= philo->last_m + philo->rules->time_to_die)
			exit(0);
	}
}

void func(t_philo *philo, t_vars *vars)
{
	pthread_create(vars->check, NULL, check, philo);
	while (1)
	{
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
		if (philo->rules->number_of_time_eat == philo->count)
			exit(1);
		ft_printf("is sleeping", philo, vars);
		ft_usleep(philo->rules->time_to_sleep);
		ft_printf("is thinking", philo, vars);
	}
}

void create_process(t_vars *vars, t_rules *input)
{
	int id;
	int status;

	id = 1;
	sem_unlink("sem");
	sem_unlink("lock_printf");
	vars->sem = sem_open("sem", O_CREAT | O_EXCL, 0644, input->philos_fork);
	vars->lock_printf = sem_open("lock_printf", O_CREAT | O_EXCL, 0644, 1);
	vars->i = 0;
	while (vars->i < input->philos_fork)
	{
		if (id != 0)
			id = fork();
		if (id == 0)
			func(&vars->philo[vars->i], vars);
		else
			vars->philo[vars->i].pid = id;
		vars->i++;
	}
	vars->i = 0;
	while (vars->i++ < input->philos_fork)
	{
		waitpid(-1, &status, 0);
		if (status == 0)
		{
			vars->philo->rules->dead = 1;
			ft_printf("is dead", vars->philo, vars);
			ft_kill(vars->philo);
		}
	}
}

void init_process(t_vars *vars, t_rules *input)
{
	vars->i = 0;
	vars->philo = malloc(sizeof(t_philo) * input->philos_fork);
	input->cur_time = get_time();
	while (vars->i < input->philos_fork)
	{
		vars->philo[vars->i].id = vars->i + 1;
		vars->philo[vars->i].count = 0;
		vars->philo[vars->i].rules = input;
		vars->philo[vars->i].last_m = input->cur_time;
		vars->i++;
	}
}

void fork_begun(t_rules *input)
{
	t_vars vars;
	init_process(&vars, input);
	create_process(&vars, input);
}

int	main(int ac, char **av)
{
	int		i;
	t_rules	*input;

	input = malloc(sizeof(t_rules));
	i = 1;
	input->dead = 0;
	if (ac != 6 && ac != 5)
		return (1);
	while (i < ac)
	{
		handling(av[i], i, input);
		i++;
	}
	fork_begun(input);
	return (0);
}

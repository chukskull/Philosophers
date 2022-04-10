/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:15:48 by snagat            #+#    #+#             */
/*   Updated: 2022/04/10 22:19:45 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

void	create_threads(t_vars *vars, t_rules *input)
{
	vars->i = 0;
	while (vars->i < input->philos_fork)
	{
		if (pthread_create(&vars->philo[vars->i].thread,
						   NULL, g_rules, &vars->philo[vars->i]) != 0)
			return;
		vars->i++;
	}
}

void	destroy_mutex(t_vars *vars, t_rules *input)
{
	vars->i = 0;
	while (vars->i < input->philos_fork)
	{
		pthread_mutex_destroy(&vars->philo[vars->i].left_fork);
		vars->i++;
	}
	pthread_mutex_destroy(&input->lock);
}

void	init_threads(t_vars *vars, t_rules *input)
{
	pthread_mutex_init(&input->lock, NULL);
	vars->philo = malloc(sizeof(t_philo) * input->philos_fork);
	vars->i = 0;
	input->cur_time = get_time();
	while (vars->i < input->philos_fork)
	{
		pthread_mutex_init(&vars->philo[vars->i].left_fork, NULL);
		vars->philo[vars->i].id = vars->i + 1;
		vars->philo[vars->i].count = 0;
		vars->philo[vars->i].rules = input;
		vars->philo[vars->i].last_m = input->cur_time;
		vars->j = vars->i + 1;
		if (vars->j == input->philos_fork)
			vars->j = 0;
		vars->philo[vars->i].right_fork = &vars->philo[vars->j].left_fork;
		vars->i++;
	}
}

void	thr_begun(t_rules *input)
{
	t_vars	vars;

	init_threads(&vars, input);
	create_threads(&vars, input);
	vars.i = 0;
	while (1)
	{
		usleep(100);
		if (input->number_of_time_eat && eat(vars.philo, input))
			break ;
		vars.time = get_time();
		if (vars.time >= vars.philo[vars.i].last_m + input->time_to_die)
		{
			input->dead = 1;
			ft_printf("is dead", &vars.philo[vars.i]);
			break ;
		}
		vars.i++;
		if (vars.i == input->philos_fork)
			vars.i = 0;
	}
	destroy_mutex(&vars, input);
}

int	main(int ac, char **av)
{
	int		i;
	t_rules	*input;

	input = malloc(sizeof(t_rules));
	i = 1;
	input->dead = 0;
	if (ac != 6 && ac != 5)
		return (EXIT_FAILURE);
	input->number_of_time_eat = 0;
	while (i < ac)
	{
		handling(av[i], i, input);
		i++;
	}
	thr_begun(input);
	return (EXIT_SUCCESS);
}

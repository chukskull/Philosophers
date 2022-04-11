/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 06:42:29 by snagat            #+#    #+#             */
/*   Updated: 2022/04/11 10:28:13 by snagat           ###   ########.fr       */
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

void	ft_wait(t_vars *vars)
{
	int	status;

	while (waitpid(-1, &status, 0) != -1)
	{
		if (status == 0)
		{
			vars->philo->rules->dead = 1;
			ft_printf("is dead", vars->philo, vars);
			ft_kill(vars->philo);
		}
	}
}

void	create_process(t_vars *vars, t_rules *input)
{
	int	id;

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
		{
			g_bonus_rules(&vars->philo[vars->i], vars);
			return ;
		}
		else
			vars->philo[vars->i].pid = id;
		vars->i++;
		usleep(100);
	}
}

void	init_process(t_vars *vars, t_rules *input)
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

void	fork_begun(t_rules *input)
{
	t_vars	vars;

	init_process(&vars, input);
	create_process(&vars, input);
	ft_wait(&vars);
}

int	main(int ac, char **av)
{
	int		i;
	long	num;
	t_rules	*input;

	input = malloc(sizeof(t_rules));
	i = 1;
	input->dead = 0;
	if (ac != 6 && ac != 5)
		return (EXIT_FAILURE);
	while (i < ac)
	{
		handling(av[i], &num, i, input);
		i++;
	}
	fork_begun(input);
	return (EXIT_SUCCESS);
}

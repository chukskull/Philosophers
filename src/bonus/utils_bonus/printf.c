/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:09:49 by snagat            #+#    #+#             */
/*   Updated: 2022/04/10 20:02:37 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <semaphore.h>
#include "bonus.h"

void	ft_printf_th(char *s, t_philo *philo)
{

	usleep(10);
	printf("[%ld] [%d] %s\n", get_time() - philo->rules->cur_time, philo->id, s);
}

void	ft_printf(char *s, t_philo *philo, t_vars *vars)
{
	sem_wait(vars->lock_printf);
	printf("[%ld] [%d] %s\n", get_time() - philo->rules->cur_time, philo->id, s);
	if (philo->rules->dead != 1)
		sem_post(vars->lock_printf);
}

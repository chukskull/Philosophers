/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:16:12 by snagat            #+#    #+#             */
/*   Updated: 2022/04/10 20:31:32 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "pthread.h"
#include <unistd.h>
#include <sys/time.h>
#include "utils.h"
#include <stdio.h>

void	*g_rules(void *philo)
{
	t_philo	*in;

	in = (t_philo *)philo;
	if (in->id % 2 == 0)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(&in->left_fork);
		ft_printf("has taken a fork", in);
		pthread_mutex_lock(in->right_fork);
		ft_printf("has taken a fork", in);
		ft_printf("is eating", in);
		in->last_m = get_time();
		in->count++;
		ft_usleep(in->rules->time_to_eat);
		pthread_mutex_unlock(&in->left_fork);
		pthread_mutex_unlock(in->right_fork);
		ft_printf("is sleeping", in);
		ft_usleep(in->rules->time_to_sleep);
		ft_printf("is thinking", in);
	}
}

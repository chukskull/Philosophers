/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:09:49 by snagat            #+#    #+#             */
/*   Updated: 2022/04/07 02:29:34 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include "philo.h"
#include <sys/time.h>
#include <unistd.h>
#include "utils.h"

void	ft_printf(char *s, t_philo *philo)
{
	pthread_mutex_t	lock;

	usleep(10);
	pthread_mutex_init(&lock, NULL);
	pthread_mutex_lock(&lock);
	printf("[%ld] [%d] %s\n", get_time() - philo->rules->cur_time, philo->id, s);
	if (philo->rules->dead != 1)
		pthread_mutex_unlock(&lock);
	else
		return ;
}

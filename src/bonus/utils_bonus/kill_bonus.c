/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:18:30 by snagat            #+#    #+#             */
/*   Updated: 2022/04/11 10:28:24 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include <signal.h>
#include <stdlib.h>

void	ft_kill(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->rules->philos_fork)
	{
		kill(philo[i].pid, SIGTERM);
		i++;
	}
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:20:43 by snagat            #+#    #+#             */
/*   Updated: 2022/04/10 21:39:55 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

int	eat(t_philo *philo, t_rules *rl)
{
	int	i;

	i = 0;
	while (i < rl->philos_fork)
	{
		if (philo[i].count < rl->number_of_time_eat)
			return (0);
		i++;
	}
	return (1);
}

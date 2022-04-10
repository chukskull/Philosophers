/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:20:43 by snagat            #+#    #+#             */
/*   Updated: 2022/04/10 16:44:35 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include <stdio.h>

int	eat(t_philo *philo, t_rules *rl)
{
	int	i;

	i = 0;
	while (i < rl->philos_fork)
	{
		if (philo->count != rl->number_of_time_eat)
			return (0);
		i++;
	}
	return (1);
}

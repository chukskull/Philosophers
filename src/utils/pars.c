/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:52:18 by snagat            #+#    #+#             */
/*   Updated: 2022/04/10 21:51:16 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

void	handling(char *av, int rules, t_rules *input)
{
	if (rules == 1)
		input->philos_fork = ft_atoi(av);
	else if (rules == 2)
		input->time_to_die = ft_atoi(av);
	else if (rules == 3)
		input->time_to_eat = ft_atoi(av);
	else if (rules == 4)
		input->time_to_sleep = ft_atoi(av);
	else if (rules == 5)
		input->number_of_time_eat = ft_atoi(av);
}

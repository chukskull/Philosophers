/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:58:11 by snagat            #+#    #+#             */
/*   Updated: 2022/04/07 02:35:30 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"

void	ft_usleep(int time)
{
	unsigned long	cur_time;
	unsigned long	breaker;

	cur_time = get_time();
	breaker = cur_time + time;
	while (1)
	{
		usleep(100);
		cur_time = get_time();
		if (cur_time == breaker)
			break ;
	}
}

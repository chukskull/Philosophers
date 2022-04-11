/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:58:11 by snagat            #+#    #+#             */
/*   Updated: 2022/04/11 09:24:52 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include <unistd.h>
#include <sys/time.h>

void	ft_usleep(int time)
{
	unsigned long	cur_time;
	unsigned long	breaker;

	cur_time = get_time();
	breaker = cur_time + time;
	usleep((time - 10) * 1000);
	while (1)
	{
		usleep(200);
		cur_time = get_time();
		if (cur_time == breaker)
			break ;
	}
}

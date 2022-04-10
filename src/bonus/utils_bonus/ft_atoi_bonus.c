/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 21:57:56 by snagat            #+#    #+#             */
/*   Updated: 2022/04/08 23:37:49 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
#include <unistd.h>
#include <stdlib.h>

void	check_num(long res)
{
	if (res > 2147483647 || res < -2147483648)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

void	var_init(t_atoi *var, char *str)
{
	var->i = 0;
	var->resultat = 0;
	if (str[var->i] == '-')
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}

int	ft_atoi(char *str, long *num)
{
	t_atoi	var;

	var_init(&var, str);
	if (str[0] == '\0')
	{
		write(1, "Error\n", 6);
		exit (1);
	}
	while (str[var.i] != '\0')
	{
		if (!(str[var.i] <= '9' && str[var.i] >= '0'))
		{
			write(1, "Error\n", 6);
			exit (1);
		}
		var.resultat *= 10;
		var.resultat += str[var.i++] - '0';
	}
	*num = var.resultat;
	check_num(*num);
	return (*num);
}

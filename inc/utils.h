/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:06:36 by snagat            #+#    #+#             */
/*   Updated: 2022/04/07 02:40:11 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>

typedef struct s_atoi
{
	int		i;
	long	resultat;
}	t_atoi;

typedef struct s_var
{
	int				i;
	unsigned long	time;
	int				j;
	t_philo			*philo;
}	t_vars;

int				ft_atoi(char *str, long *num);
void			handling(char *av, long *num, int rules, t_rules *input);
unsigned long	get_time(void);
void			ft_printf(char *s, t_philo *philo);

#endif
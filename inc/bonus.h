/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snagat <snagat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 08:37:40 by snagat            #+#    #+#             */
/*   Updated: 2022/04/10 23:15:22 by snagat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H


# include <sys/time.h>
# include <semaphore.h>

typedef struct g_rules
{
	int					philos_fork;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_time_eat;
	struct timeval		simulations;
	unsigned long		cur_time;
	int					dead;
}	t_rules;

typedef struct s_philo
{
	int				id;
	t_rules			*rules;
	unsigned long	last_m;
	int				count;
	int				pid;
}	t_philo;

typedef struct s_var
{
	int				i;
	unsigned long	time;
	int				j;
	sem_t			*sem;
	sem_t			*lock_printf;
	t_philo			*philo;
	pthread_t		*check;
	
}	t_vars;

typedef struct s_atoi
{
	int		i;
	long	resultat;
}	t_atoi;


int				ft_atoi(char *str);
void			handling(char *av, int rules, t_rules *input);
unsigned long	get_time(void);
void			ft_usleep(int time);
void			ft_printf(char *s, t_philo *philo, t_vars *vars);
int				eat(t_philo *philo, t_rules *rl);


#endif
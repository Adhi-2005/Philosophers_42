/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 08:14:31 by adshafee          #+#    #+#             */
/*   Updated: 2024/09/13 17:28:04 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

# define MAX_PHILOS 200

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"

typedef struct info
{
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				num_of_philo;
	bool			is_dead;
	pthread_mutex_t	dlock;
	pthread_mutex_t	print_lock;
}	t_info;

typedef struct philo
{
	int				id;
	int				fork;
	int				m_fork;
	long			life;
	int				times_to_eat;
	pthread_t		thread;
	pthread_mutex_t	lock;
	pthread_mutex_t	rlock;
	struct timeval	start_t;
	struct timeval	life_t;
	struct info		*philo_info;
	struct philo	*next;
}	t_philo;

void	print_info(t_philo *philo, int print_order);
bool	init_philo(t_philo *philo, int argc, char **argv);
int		is_philo_dead(t_philo *philo);
int		ft_atoi(const char	*str);
int		*ft_single_philo(t_philo *philo, int ttime);
bool	philo_eat(t_philo *philo);
void	ft_mutex(t_philo *philo, int lock_flag);
void	lock_order(t_philo *philo);
long	n_timestamp(struct timeval *time);
size_t	timestamp_new(void);

void	*monitor(void *arg);

//argumet checking related functions...

int		error_arg(int ac, char **av);
int		ft_isdigit(int i);
int		argument_check(char **av);
void	print_error_philo_is_zero(void);
void	print_error_not_a_digit(void);
void	print_error_exit(void);
void	print_null_msg(void);

#endif
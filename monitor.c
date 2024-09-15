/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:26:08 by adshafee          #+#    #+#             */
/*   Updated: 2024/09/14 13:31:55 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

static int	check_philosophers_meals(t_philo *philos)
{
	int	i;
	int	meals_count;

	meals_count = 0;
	i = -1;
	while (++i < philos->philo_info->num_of_philo)
	{
		pthread_mutex_lock(&philos[i].lock);
		if (philos->times_to_eat != -1
			&& philos[i].times_to_eat >= philos->times_to_eat)
			meals_count++;
		pthread_mutex_unlock(&philos[i].lock);
	}
	return (meals_count);
}

static int	check_philosophers_death(t_philo *philos)
{
	int		i;
	long	time_elapsed;

	i = -1;
	while (++i < philos->philo_info->num_of_philo)
	{
		pthread_mutex_lock(&philos[i].lock);
		time_elapsed = get_current_time() - philos[i].life;
		if (time_elapsed > philos->philo_info->time_to_die)
		{
			pthread_mutex_lock(&philos->philo_info->dlock);
			philos->philo_info->is_dead = true;
			pthread_mutex_unlock(&philos->philo_info->dlock);
			print_info(philos, 5);
			pthread_mutex_unlock(&philos[i].lock);
			return (1);
		}
		pthread_mutex_unlock(&philos[i].lock);
	}
	return (0);
}

void	*monitor(void *arg)
{
	t_philo	*philos;
	int		meals_count;

	philos = (t_philo *)arg;
	while (1)
	{
		if (check_philosophers_death(philos))
			return (NULL);
		meals_count = check_philosophers_meals(philos);
		if (meals_count == philos->philo_info->num_of_philo)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}

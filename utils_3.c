/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 08:14:46 by adshafee          #+#    #+#             */
/*   Updated: 2024/09/18 19:34:59 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_mutex(t_philo *philo, int lock_flag)
{
	if (lock_flag)
		pthread_mutex_lock(&philo->philo_info->dlock);
	else
		pthread_mutex_unlock(&philo->philo_info->dlock);
}

void	lock_order(t_philo *philo)
{
	if (philo->id % philo->philo_info->num_of_philo)
	{
		pthread_mutex_lock(&philo->lock);
		pthread_mutex_lock(&philo->next->lock);
	}
	else
	{
		pthread_mutex_lock(&philo->next->lock);
		pthread_mutex_lock(&philo->lock);
	}
}

long	n_timestamp(struct timeval *time)
{
	struct timeval	c_time;
	long			res;

	gettimeofday(&c_time, NULL);
	res = ((c_time.tv_sec - time->tv_sec) * 1000) + ((c_time.tv_usec
				- time->tv_usec) / 1000);
	return (res);
}

size_t	timestamp_new(void)
{
	struct timeval	c_time;
	size_t			time;

	gettimeofday(&c_time, NULL);
	time = (c_time.tv_sec * 1000000 + c_time.tv_usec);
	return (time);
}

void	print_null_msg(void)
{
	printf(RED"Max philo should be 200\n"RESET);
}

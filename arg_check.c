/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adshafee <adshafee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 08:27:02 by adshafee          #+#    #+#             */
/*   Updated: 2024/09/13 11:44:32 by adshafee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	argument_check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	print_error_philo_is_zero(void)
{
	printf(RED"INVALID ARGUMENT DETECTED\n"RESET);
	printf(RED"Number of philo cannot be Zero"RESET);
}

void	print_error_not_a_digit(void)
{
	printf(RED"INVALID ARGUMENT DETECTED\n"RESET);
	printf(RED"non digits are present"RESET);
}

void	print_error_exit(void)
{
	printf(RED"INVALID ARGUMENT DETECTED\n"RESET);
	printf(BLUE"Argument: "RESET);
	printf(YELLOW"./philo 'no.philo' 'time_to_die' "RESET);
	printf(YELLOW"'time_to_eat' 'time_to_sleep'\n"RESET);
	printf(BLUE"Extra optional argument: "RESET);
	printf(YELLOW"'no.of_times_each_philo_should_eat'\n"RESET);
}

int	error_arg(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (print_error_exit(), 1);
	if (ft_atoi(av[1]) > 200)
		return (print_null_msg(), 1);
	if (!argument_check(av))
		return (print_error_not_a_digit(), 1);
	if (ft_atoi(av[1]) == 0)
		return (print_error_philo_is_zero(), 1);
	return (0);
}

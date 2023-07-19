/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preflight_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:45:20 by malaakso          #+#    #+#             */
/*   Updated: 2023/07/19 16:19:55 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_err	check_argc(int ac)
{
	if (ac >= 5 && ac <= 6)
		return (SUCCESS);
	printf("Incorrect number of arguments!\n");
	printf("Usage: ./philo number_of_philosophers time_to_die time_to_eat");
	printf(" time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	return (FAIL);
}

static t_err	check_number_of_philosophers(char *number_of_philosophers_arg)
{
	int	philo_count;

	philo_count = my_atoi(number_of_philosophers_arg);
	if (philo_count > 0 && philo_count <= 250)
		return (SUCCESS);
	return (FAIL);
}

static t_err	check_other_arguments(int ac, char **av)
{
	int	i;

	i = 2;
	while (av[i] < ac)
	{
		if (my_atoi(av[i] < 0))
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

t_err	preflight_checks(int ac, char **av)
{
	if (check_argc(ac) != SUCCESS)
		return (FAIL);
	if (check_number_of_philosophers(av[1]) != SUCCESS)
		return (FAIL);
	if (check_other_arguments(ac, av) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}

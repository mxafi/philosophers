/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:04:32 by malaakso          #+#    #+#             */
/*   Updated: 2023/07/19 18:22:20 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_err	init_memory(t_common_data **data, int ac, char **av)
{
	t_common_data	*tmp;

	tmp = malloc(sizeof(t_common_data));
	if (!tmp)
		return (NULL);
	memset(tmp, 0, sizeof(t_common_data));
	tmp->number_of_philosophers = my_atoi(av[1]);
	tmp->time_to_die = my_atoi(av[2]);
	tmp->time_to_eat = my_atoi(av[3]);
	tmp->time_to_sleep = my_atoi(av[4]);
	if (ac == 6)
		tmp->number_of_times_each_philosopher_must_eat = my_atoi(av[5]);
	else
		tmp->number_of_times_each_philosopher_must_eat = -1;
	if (init_philosophers(data) != SUCCESS || init_mutexes(data) != SUCCESS) // TODO init_philosopher init_mutexes
	{
		destroy_memory_struct(data);
		return (FAIL);
	}
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_common_data	*data;
	// DEBUG: Makefile has debug flags and extra CFLAGS to remove before submission
	if (preflight_checks(ac, av) != SUCCESS)
		return (1);
	if (init_memory(&data, ac, av) != SUCCESS)
		return (1);
	return (0);
}

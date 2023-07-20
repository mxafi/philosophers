/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:04:32 by malaakso          #+#    #+#             */
/*   Updated: 2023/07/20 14:13:01 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_err	set_fork_ids(t_common_data *data, int philo_id)
{
	if (philo_id % 2)
	{
		// not divisible by 2, odd
	}
	else
	{
		// even
	}
}

t_err	init_philosophers(t_common_data *data)
{
	int	i;

	data->philosophers = malloc(sizeof(t_philosopher *)
			* data->number_of_philosophers);
	if (!data->philosophers)
		return (MALLOC_FAIL);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		data->philosophers[i] = malloc(sizeof(t_philosopher));
		if (!data->philosophers[i])
			return (MALLOC_FAIL);
		memset(data->philosophers[i], 0, sizeof(t_philosopher));
		data->philosophers[i]->philo_id = i + 1;
		data->philosophers[i]->common_data = data;
		if (set_fork_ids(data, data->philosophers[i]->philo_id) != SUCCESS) //TODO
			return (FAIL);
		if (pthread_mutex_init(&data->philosophers[i]->eat_count_lock, NULL)
			|| pthread_mutex_init(&data->philosophers[i]->eat_finished_lock,
				NULL)
			|| pthread_mutex_init(&data->philosophers[i]->eat_timestamp_lock,
				NULL))
			return (MUTEX_FAIL);
		i++;
	}
}

t_err	init_memory(t_common_data **data, int ac, char **av)
{
	*data = malloc(sizeof(t_common_data));
	if (!*data)
		return (NULL);
	memset(*data, 0, sizeof(t_common_data));
	(*data)->number_of_philosophers = my_atoi(av[1]);
	(*data)->time_to_die = my_atoi(av[2]);
	(*data)->time_to_eat = my_atoi(av[3]);
	(*data)->time_to_sleep = my_atoi(av[4]);
	if (ac == 6)
		(*data)->number_of_times_each_philosopher_must_eat = my_atoi(av[5]);
	else
		(*data)->number_of_times_each_philosopher_must_eat = -1;
	if (init_philosophers(*data) != SUCCESS || init_mutexes(*data) != SUCCESS) // TODO init_philosopher init_mutexes
	{
		destroy_memory_struct(*data); //TODO
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

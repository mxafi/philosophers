/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:04:32 by malaakso          #+#    #+#             */
/*   Updated: 2023/07/24 13:14:32 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_err	join_threads(t_common_data *d)
{
	int		i;
	t_err	ret;

	ret = SUCCESS;
	i = 0;
	while (i < d->number_of_philosophers)
	{
		if (pthread_join(d->philosophers[i]->thread_id, NULL))
			ret = JOIN_FAIL;
		i++;
	}
	if (pthread_join(d->monitor_id, NULL))
		ret = JOIN_FAIL;
	return (ret);
}

int	main(int ac, char **av)
{
	t_common_data	*data;
	// DEBUG: Makefile has debug flags and extra CFLAGS to remove before submission
	if (preflight_checks(ac, av) != SUCCESS)
		return (1);
	if (init_memory(&data, ac, av) != SUCCESS)
		return (1);
	// actual simulation stuffs.
	if (join_threads(data) != SUCCESS)
		printf("Error: join_threads\n");
	free_memory(data);
	return (0);
}

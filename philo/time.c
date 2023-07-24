/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:49:29 by malaakso          #+#    #+#             */
/*   Updated: 2023/07/24 12:34:12 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Get the timestamp from the start of
 * the simulation to now in microseconds.
 * @param start timeval of the start of the simulation.
 * @return size_t - number of microseconds since the start of the simulation.
 */
size_t	get_timestamp(struct timeval start)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (((now.tv_sec - start.tv_sec) * 1000000)
		+ (now.tv_usec - start.tv_usec));
}

/**
 * @brief Transform microseconds to milliseconds.
 * 
 * @param microseconds number of microseconds.
 * @return size_t - number of milliseconds.
 */
size_t	us_to_ms(size_t microseconds)
{
	return (microseconds / 1000);
}

void	philo_usleep(t_common_data *d, size_t sleep_duration_microseconds)
{
	size_t	wake_timestamp;

	wake_timestamp = get_timestamp(d->start)
		+ sleep_duration_microseconds;
	while (get_timestamp(d->start) < wake_timestamp)
	{
		if (is_philo_finished(d) == TRUE)
			break ;
		usleep(500);
	}
}

/**
 * @brief Makes the philosopher sleep for time_to_sleep, checks for
 * end of simulation before printing and during sleep.
 * 
 * @param p the philosopher to sleep.
 * @return t_err - positive on failure.
 */
t_err	philo_sleep(t_philosopher *p)
{
	if (philo_stdout(p, "is sleeping") != SUCCESS)
		return (FAIL);
	philo_usleep(p->common_data, p->common_data->time_to_sleep);
	return (SUCCESS);
}

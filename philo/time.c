/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:49:29 by malaakso          #+#    #+#             */
/*   Updated: 2023/07/19 17:52:38 by malaakso         ###   ########.fr       */
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

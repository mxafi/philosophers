/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:05:51 by malaakso          #+#    #+#             */
/*   Updated: 2023/07/19 11:37:46 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// for memset
# include <string.h>

// for printf
# include <stdio.h>

// for malloc, free
# include <stdlib.h>

// for write, usleep
# include <unistd.h>

// for gettimeofday
# include <sys/time.h>

// for pthread functions
# include <pthread.h>

// typedefs
typedef struct s_fork
{
	pthread_mutex_t	fork_mutex;
	
}	t_fork;

#endif
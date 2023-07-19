/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:05:51 by malaakso          #+#    #+#             */
/*   Updated: 2023/07/19 17:06:15 by malaakso         ###   ########.fr       */
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

// for system limits
# include <limits.h>

typedef struct s_common_data
{
	pthread_t		monitor_id;
	pthread_mutex_t	*forks;
	t_philosopher	**philosophers;
	const int		number_of_philosophers;
	const int		time_to_die;
	const int		time_to_eat;
	const int		time_to_sleep;
	const int		number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	stdout_lock;
	
}	t_common_data;

typedef struct s_philosopher
{
	int				philo_id;
	pthread_t		thread_id;
	int				fork_id[2];
	int				eat_count;
	pthread_mutex_t	eat_count_lock;
	int				eat_finished;
	pthread_mutex_t	eat_finished_lock;
	size_t			eat_timestamp;
	pthread_mutex_t	eat_timestamp_lock;

}					t_philosopher;

typedef enum e_err
{
	SUCCESS,
	FAIL
}	t_err;

int		my_atoi(const char *str);
t_err	preflight_checks(int ac, char **av);

#endif
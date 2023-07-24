/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:53:14 by malaakso          #+#    #+#             */
/*   Updated: 2023/07/24 13:00:57 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_err	philo_eat_take_forks(t_philosopher *p)
{
	pthread_mutex_lock(&p->common_data->forks[p->fork_id[0]]);
	if (philo_stdout(p, "has taken a fork") != SUCCESS)
	{
		pthread_mutex_unlock(&p->common_data->forks[p->fork_id[0]]);
		return (EAT_FAIL);
	}
	pthread_mutex_lock(&p->common_data->forks[p->fork_id[1]]);
	if (philo_stdout(p, "has taken a fork") != SUCCESS)
	{
		pthread_mutex_unlock(&p->common_data->forks[p->fork_id[0]]);
		pthread_mutex_unlock(&p->common_data->forks[p->fork_id[1]]);
		return (EAT_FAIL);
	}
	return (SUCCESS);
}

void	philo_eat_mod_values(t_err *ret, t_philosopher *p)
{
	pthread_mutex_lock(&p->eat_count_lock);
	p->eat_count++;
	if (p->eat_count
		== p->common_data->number_of_times_each_philosopher_must_eat)
	{
		pthread_mutex_lock(&p->eat_finished_lock);
		p->eat_finished = TRUE;
		pthread_mutex_unlock(&p->eat_finished_lock);
		*ret = EAT_FAIL;
	}
	pthread_mutex_unlock(&p->eat_count_lock);
	pthread_mutex_lock(&p->eat_timestamp_lock);
	p->eat_timestamp = get_timestamp(p->common_data->start);
	pthread_mutex_unlock(&p->eat_timestamp_lock);
}

t_err	philo_eat(t_philosopher *p)
{
	t_err	ret;

	ret = SUCCESS;
	if (philo_eat_take_forks(p) != SUCCESS)
		return (EAT_FAIL);
	philo_eat_mod_values(&ret, p);
	if (philo_stdout(p, "is eating") != SUCCESS)
		ret = EAT_FAIL;
	pthread_mutex_unlock(&p->common_data->forks[0]);
	pthread_mutex_unlock(&p->common_data->forks[1]);
	return (ret);
}

void	*philo_routine(t_philosopher *p)
{
	if (p->philo_id % 2 == 0)
	{
		if (philo_sleep(p) != SUCCESS)
			return (NULL);
	}
	while (1)
	{
		if (philo_eat(p) != SUCCESS)
			return (NULL);
		if (philo_sleep(p) != SUCCESS)
			return (NULL);
		if (philo_stdout(p, "is thinking") != SUCCESS)
			return (NULL);
		// sleep for 500us here ???
	}
	return (NULL);
}

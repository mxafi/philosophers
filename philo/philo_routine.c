/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:53:14 by malaakso          #+#    #+#             */
/*   Updated: 2023/07/25 13:05:16 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_err	philo_eat_take_forks(t_philosopher *p)
{
	printf("Debug: philo_eat_take_forks: philo%i fork0 waiting\n", p->philo_id);
	pthread_mutex_lock(&p->common_data->forks[p->fork_id[0]]);
	if (philo_stdout(p, "has taken a fork") != SUCCESS
		|| p->fork_id[0] == p->fork_id[1])
	{
		printf("Debug: philo_eat_take_forks: philo%i fork0 fail\n", p->philo_id);
		pthread_mutex_unlock(&p->common_data->forks[p->fork_id[0]]);
		return (EAT_FAIL);
	}
	printf("Debug: philo_eat_take_forks: philo%i fork0 success\n", p->philo_id);
	printf("Debug: philo_eat_take_forks: philo%i fork1 waiting\n", p->philo_id);
	pthread_mutex_lock(&p->common_data->forks[p->fork_id[1]]);
	if (philo_stdout(p, "has taken a fork") != SUCCESS)
	{
		printf("Debug: philo_eat_take_forks: philo%i fork1 fail\n", p->philo_id);
		pthread_mutex_unlock(&p->common_data->forks[p->fork_id[0]]);
		pthread_mutex_unlock(&p->common_data->forks[p->fork_id[1]]);
		return (EAT_FAIL);
	}
	printf("Debug: philo_eat_take_forks: philo%i fork1 success\n", p->philo_id);
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

void	*philo_routine(void *v_p)
{
	t_philosopher	*p;

	p = (t_philosopher *)v_p;
	if (p->philo_id % 2 == 0)
	{
		if (philo_sleep(p) != SUCCESS)
			return (NULL);
	}
	while (1)
	{
		//printf("Debug: philo_routine: eat start\n");
		if (philo_eat(p) != SUCCESS)
			return (NULL);
		//printf("Debug: philo_routine: eat end\n");
		if (philo_sleep(p) != SUCCESS)
			return (NULL);
		if (philo_stdout(p, "is thinking") != SUCCESS)
			return (NULL);
		// sleep for 500us here ???
		//printf("Debug: philo_routine: loop done\n");
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaakso <malaakso@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 22:04:32 by malaakso          #+#    #+#             */
/*   Updated: 2023/07/20 17:53:55 by malaakso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_common_data	*data;
	// DEBUG: Makefile has debug flags and extra CFLAGS to remove before submission
	if (preflight_checks(ac, av) != SUCCESS)
		return (1);
	if (init_memory(&data, ac, av) != SUCCESS)
		return (1);
	// actual simulation stuffs.
	// joining stuffs.
	free_memory(data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   process.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 14:04:04 by gozturk       #+#    #+#                 */
/*   Updated: 2023/08/24 14:04:05 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->shared_data->number_of_philosophers == 1)
	{
		thread_safe_print("has taken a fork", philo);
		usleep(philo->shared_data->time_to_die * 1000);
	}
	if (philo->id % 2 == 1)
		usleep(philo->shared_data->time_to_eat * 1000);
	while (check_simulation_ends(philo->shared_data) == 0
		&& philo->must_eat != 0)
	{
		thread_safe_print("is thinking", philo);
		eating(philo);
		sleeping(philo);
	}
	return (NULL);
}

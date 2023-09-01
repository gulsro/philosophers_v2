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

static	void	unlock_stop_simulation(t_philo *philo)
{
	pthread_mutex_unlock(&philo->shared_data->create);
	stop_simulation(philo->shared_data);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->shared_data->create);
	if (philo->shared_data->created_threads != philo->number_of_philosophers)
		return (unlock_stop_simulation(philo), NULL);
	pthread_mutex_unlock(&philo->shared_data->create);
	if (philo->shared_data->number_of_philosophers == 1)
	{
		thread_safe_print("has taken a fork", philo);
		usleep(philo->shared_data->time_to_die * 1000);
	}
	if (check_simulation_ends(philo->shared_data) == 0 && philo->id % 2 == 1)
		usleep(philo->shared_data->time_to_eat * 1000);
	while (check_simulation_ends(philo->shared_data) == 0
		&& philo->must_eat != 0)
	{
		thread_safe_print("is thinking", philo);
		if (philo->must_eat != 0)
			eating(philo);
		if (philo->must_eat == 0)
			break ;
		sleeping(philo);
	}
	return (NULL);
}

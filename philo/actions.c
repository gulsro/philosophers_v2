/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 14:02:59 by gozturk       #+#    #+#                 */
/*   Updated: 2023/08/24 14:03:01 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->shared_data->fork[philo->id - 1]);
	thread_safe_print("has taken a fork", philo);
	pthread_mutex_lock(&philo->shared_data->fork[philo->id
		% philo->shared_data->number_of_philosophers]);
	thread_safe_print("has taken a fork", philo);
	set_meal_number(philo);
	set_meal_time(philo);
	thread_safe_print("is eating", philo);
	sleep_tight(philo->shared_data->time_to_eat);
	pthread_mutex_unlock(&philo->shared_data->fork[philo->id - 1]);
	pthread_mutex_unlock(&philo->shared_data->fork[philo->id
		% philo->shared_data->number_of_philosophers]);
}

void	sleeping(t_philo *philo)
{
	thread_safe_print("is sleeping", philo);
	sleep_tight(philo->shared_data->time_to_sleep);
}

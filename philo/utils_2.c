/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 14:04:30 by gozturk       #+#    #+#                 */
/*   Updated: 2023/08/24 14:04:31 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	last_meal_time(t_philo *philo)
{
	long	last_meal_time;

	pthread_mutex_lock(&philo->shared_data->meal);
	last_meal_time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->shared_data->meal);
	return (last_meal_time);
}

void	set_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->shared_data->meal);
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(&philo->shared_data->meal);
}

void	set_meal_number(t_philo *philo)
{
	pthread_mutex_lock(&philo->shared_data->meal);
	philo->must_eat--;
	pthread_mutex_unlock(&philo->shared_data->meal);
}

#include "philo.h"

int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->shared_data->fork[philo->id - 1]);
	thread_safe_print("has taken a fork", philo);
	pthread_mutex_lock(&philo->shared_data->fork[philo->id % philo->shared_data->number_of_philosophers]);
	thread_safe_print("has taken a fork", philo);
	pthread_mutex_lock(&philo->private_mutex);
	philo->last_meal_time = get_current_time();
	philo->eaten_meals++;
	pthread_mutex_unlock(&philo->private_mutex);
	// if (philo->shared_data->philos_are_full == 1)
	// {
	// 	//pthread_mutex_unlock(&philo->shared_data->meal);
	// 	pthread_mutex_unlock(&philo->shared_data->fork[philo->id - 1]);
	// 	pthread_mutex_unlock(&philo->shared_data->fork[philo->id % philo->shared_data->number_of_philosophers]);
	// 	return 1;
	// }
	// //pthread_mutex_unlock(&philo->shared_data->meal);

	thread_safe_print("is eating", philo);



	pthread_mutex_lock(&philo->shared_data->meal);
	sleep_tight(philo->shared_data->time_to_eat);

	// if (philo->shared_data->must_eat > 0)
	// 	philo->shared_data->must_eat_counter++;
	// pthread_mutex_unlock(&philo->shared_data->meal);

	// if (check_simulation_ends(philo) == 1)
	// {
	// 	pthread_mutex_unlock(&philo->shared_data->fork[philo->id - 1]);
	// 	pthread_mutex_unlock(&philo->shared_data->fork[philo->id % philo->shared_data->number_of_philosophers]);
	// 	return (ERROR);
	// }
	pthread_mutex_unlock(&philo->shared_data->fork[philo->id - 1]);
	pthread_mutex_unlock(&philo->shared_data->fork[philo->id % philo->shared_data->number_of_philosophers]);
	return (1);
}

void	thinking(t_philo *philo)
{
	thread_safe_print("is thinking", philo);
}

int    sleeping(t_philo *philo)
{
	thread_safe_print("is sleeping", philo);
	sleep_tight(philo->shared_data->time_to_sleep);
	// pthread_mutex_lock(&philo->shared_data->meal);
	// if (sleep_tight(philo->shared_data->time_to_sleep, philo) == 1)
	// {
	// 	pthread_mutex_unlock(&philo->shared_data->meal);
	// 	return (ERROR);
	// }
	// pthread_mutex_unlock(&philo->shared_data->meal);
	return (0);
}

#include "philo.h"

void    taking_forks(t_philo *philo)
{
	// if (philo->id % 2 == 1)
	// 	usleep(50);
	pthread_mutex_lock(&philo->shared_data->fork[philo->id - 1]);
	pthread_mutex_lock(&philo->shared_data->fork[philo->id % philo->shared_data->number_of_philosophers]);
	printf("%ld %d has taken a fork\n", elapsed_time(philo->start_time), philo->id);
	printf("%ld %d has taken a fork\n", elapsed_time(philo->start_time), philo->id);
	// pthread_mutex_unlock(&philo->shared_data->fork[philo->id % philo->shared_data->number_of_philosophers]);
	// pthread_mutex_unlock(&philo->shared_data->fork[philo->id - 1]);
}

int	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->shared_data->print);
	if (philo->shared_data->philos_are_full == 1)
	{
		pthread_mutex_unlock(&philo->shared_data->print);
		return 1;
	}
	printf("%ld %d is eating\n", elapsed_time(philo->start_time), philo->id);
	philo->last_meal_time = get_current_time();
	sleep_tight(philo->shared_data->time_to_eat, philo);
	if (philo->shared_data->must_eat > 0)
		philo->shared_data->must_eat_counter++;
	if (check_simulation_ends(philo) == 1)
	{
		pthread_mutex_unlock(&philo->shared_data->fork[philo->id - 1]);
		pthread_mutex_unlock(&philo->shared_data->fork[philo->id % philo->shared_data->number_of_philosophers]);
		return (ERROR);
	}
	pthread_mutex_unlock(&philo->shared_data->print);
	pthread_mutex_unlock(&philo->shared_data->fork[philo->id - 1]);
	pthread_mutex_unlock(&philo->shared_data->fork[philo->id % philo->shared_data->number_of_philosophers]);
	return (0);
}

void	thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->shared_data->print);
	printf("%ld %d is thinking\n", elapsed_time(philo->start_time), philo->id);
	//sleep_tight(50, philo->shared_data);
	pthread_mutex_unlock(&philo->shared_data->print);
}

int    sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->shared_data->print);
	printf("%ld %d is sleeping\n", elapsed_time(philo->start_time), philo->id);
	if (sleep_tight(philo->shared_data->time_to_sleep, philo) == 1)
		return (ERROR);
	pthread_mutex_unlock(&philo->shared_data->print);
//	sleep_tight(philo->shared_data->time_to_sleep);
	return (0);
}

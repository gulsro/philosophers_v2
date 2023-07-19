#include "philo.h"

int check_simulation_ends(t_philo *philo)
{
	if (philo->dead == 1)
		return (1);
	pthread_mutex_lock(&philo->shared_data->meal);
	if (philo->shared_data->must_eat != 0)
	{
		if (check_philo_done_eating(philo) == 1)
		{
			pthread_mutex_unlock(&philo->shared_data->meal);
			return (1);
		}
	}
	if (check_starvation(philo) == 1)
	{
		pthread_mutex_unlock(&philo->shared_data->meal);
		return (1);
	}
	pthread_mutex_unlock(&philo->shared_data->meal);
	return (0);
}

int check_philo_done_eating(t_philo *philo)
{
	if (philo->shared_data->must_eat == 0) // add this check to simul ends
	{
		return (0);
	}
	if (philo->shared_data->must_eat_counter == philo->shared_data->must_eat) //!!!!!!
	{
		//philo->done_eating = 1;
		//printf("philo id %d\n", philo->id);
		philo->shared_data->philos_are_full = 1;
	}
	if (philo->shared_data->philos_are_full == 1)
	{
		philo->shared_data->stop_simulation = 1;
		//pthread_mutex_unlock(&philo->shared_data->meal);
		return (1);
	}
	return (0);
}

int    check_starvation(t_philo *philo)
{
	if (get_current_time() - philo->last_meal_time > philo->shared_data->time_to_die && philo->done_eating == 0)
	{
		printf("%ld %d died\n", elapsed_time(philo->start_time), philo->id);
		philo->dead = 1;
		philo->shared_data->stop_simulation = 1;
		pthread_mutex_unlock(&philo->shared_data->meal);
		return (1);
	}
	return (0);
}
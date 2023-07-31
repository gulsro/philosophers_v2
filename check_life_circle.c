#include "philo.h"

int check_simulation_ends(t_shared_data *shared_data)
{
	pthread_mutex_lock(&shared_data->stop_check);
	if (shared_data->stop_simulation == 1)
	{
		pthread_mutex_unlock(&shared_data->stop_check);
		return (1);
	}
	pthread_mutex_unlock(&shared_data->stop_check);
	return (0);
}

// int check_philo_tummy_full(t_philo *philo)
// {
// 	if (philo->eaten_meals == philo->shared_data->must_eat)
// 	{
// 		pthread_mutex_lock(&philo->private_mutex);
// 		philo->done_eating = 1;
// 		pthread_mutex_unlock(&philo->private_mutex);
// 		return (1);
// 	}
// 	return (0);
// }

// int check_all_philos_done_eating(t_philo *philo)
// {
// 	// if (philo->shared_data->must_eat == 0) // add this check to simul ends
// 	// {
// 	// 	return (0);
// 	// }
// 	//if (philo->shared_data->must_eat_counter == philo->shared_data->must_eat
// 	//&& philo->eaten_meals == philo->shared_data->must_eat) 
// 	if (check_philo_tummy_full(philo) == 1
// 		&& philo->shared_data->must_eat_counter == (philo->shared_data->number_of_philosophers)*(philo->shared_data->must_eat))
// 	{
// 		philo->shared_data->philos_are_full = 1;
// 		philo->shared_data->stop_simulation = 1;
// 		return (1);
// 	}
// 	// if (philo->shared_data->philos_are_full == 1)
// 	// {
// 	// 	philo->shared_data->stop_simulation = 1;
// 	// 	//pthread_mutex_unlock(&philo->shared_data->meal);
// 	// 	return (1);
// 	// }
// 	return (0);
// }

int    check_starvation(t_philo *philo_arr, t_shared_data *shared_data)
{
	int i;

	i = 0;
	while (i < shared_data->number_of_philosophers)
	{
		if (get_current_time() - philo_arr[i].last_meal_time > philo_arr[i].shared_data->time_to_die)
		{
			pthread_mutex_lock(&shared_data->stop_check);
			philo_arr[i].shared_data->stop_simulation = 1;
			pthread_mutex_unlock(&shared_data->stop_check);
			thread_safe_print("died", &philo_arr[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

void check_routine(t_philo *philo_arr, t_shared_data *shared_data)
{
	while (check_simulation_ends(shared_data) == 0)
	{
		check_starvation(philo_arr, shared_data);
		usleep(1000);
	}
	//join_threads(philo_arr);
	destroy_mutexes(shared_data);
}





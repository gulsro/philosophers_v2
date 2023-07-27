#include "philo.h"

int check_simulation_ends(t_philo *philo)
{
	if (philo->dead == 1)
		return (1);
//	pthread_mutex_lock(&philo->shared_data->meal);
	if (philo->shared_data->must_eat != 0)
	{
		if (check_all_philos_done_eating(philo) == 1)
		{
			//pthread_mutex_unlock(&philo->shared_data->meal);
			return (1);
		}
	}
	if (check_starvation(philo) == 1)
	{
		//pthread_mutex_unlock(&philo->shared_data->meal);
		return (1);
	}
	//pthread_mutex_unlock(&philo->shared_data->meal);
	return (0);
}

int check_philo_tummy_full(t_philo *philo)
{
	if (philo->eaten_meals == philo->shared_data->must_eat)
	{
		pthread_mutex_lock(&philo->private_mutex);
		philo->done_eating = 1;
		pthread_mutex_unlock(&philo->private_mutex);
		return (1);
	}
	return (0);
}

int check_all_philos_done_eating(t_philo *philo)
{
	// if (philo->shared_data->must_eat == 0) // add this check to simul ends
	// {
	// 	return (0);
	// }
	//if (philo->shared_data->must_eat_counter == philo->shared_data->must_eat
	//&& philo->eaten_meals == philo->shared_data->must_eat) 
	if (check_philo_tummy_full(philo) == 1
		&& philo->shared_data->must_eat_counter == (philo->shared_data->number_of_philosophers)*(philo->shared_data->must_eat))
	{
		philo->shared_data->philos_are_full = 1;
		philo->shared_data->stop_simulation = 1;
		return (1);
	}
	// if (philo->shared_data->philos_are_full == 1)
	// {
	// 	philo->shared_data->stop_simulation = 1;
	// 	//pthread_mutex_unlock(&philo->shared_data->meal);
	// 	return (1);
	// }
	return (0);
}

int    check_starvation(t_philo *philo)
{
	if (get_current_time() - philo->last_meal_time > philo->shared_data->time_to_die
		&& philo->done_eating == 0)
	{
		thread_safe_print("died", philo);
		philo->dead = 1;
		philo->shared_data->stop_simulation = 1;
		return (1);
	}
	return (0);
}

int check_philo_arr(t_shared_data *shared_data, t_philo *philo_arr)
{
	int i;
	while (1)
	{
		i = 0;
		while (i < shared_data->number_of_philosophers)
		{
			//printf("WOOOO\n");
			check_starvation(&philo_arr[i]);
			if (philo_arr[i].dead == 1)
				return (1);
			if (check_simulation_ends(&philo_arr[i]) == 1)
				return (1);
			i++;
		}
		usleep(1000);
	}
	return (0);
}





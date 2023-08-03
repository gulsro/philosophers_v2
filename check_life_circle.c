#include "philo.h"

int	check_simulation_ends(t_shared_data *shared_data)
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

int	check_starvation(t_shared_data *shared_data)
{
	t_philo *philo_arr;
	int i;

	philo_arr = shared_data->philo_arr;
	i = 0;
	while (i < shared_data->number_of_philosophers)
	{
		if (get_current_time() - last_meal_time(&philo_arr[i]) > shared_data->time_to_die)
		{
			stop_simulation(shared_data);
			if (philo_arr[i].must_eat != 0)
				thread_safe_print("died", &philo_arr[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

void	check_routine(t_shared_data *shared_data)
{
	while (check_simulation_ends(shared_data) == 0)
	{
		check_starvation(shared_data);
		usleep(1000);
	}
	destroy_mutexes(shared_data);
}





#include "philo.h"

// Initializes philo struct --it will be called in init_threads_mutex_philo()
t_philo	*init_philo_arr(t_shared_data *shared_data)
{
	t_philo *philo_arr;
	int	i;

	philo_arr = shared_data->philo_arr;
	i = 0;
	philo_arr = malloc(sizeof(t_philo) * shared_data->number_of_philosophers);
	if (!philo_arr)
		return (NULL);
	while (i < shared_data->number_of_philosophers)
	{
		philo_arr[i].shared_data = shared_data;
		philo_arr[i].number_of_philosophers = shared_data->number_of_philosophers;
		philo_arr[i].id = i + 1;
		philo_arr[i].start_time = get_current_time();;
		philo_arr[i].last_meal_time = philo_arr[i].start_time;
		philo_arr[i].dead = 0;
		philo_arr[i].must_eat = shared_data->must_eat;
		i++;
	}
	return (philo_arr);
}

// Initializes both print mutex and fork mutexes --it will be called in init_threads_mutex_philo()
int	init_mutexes(t_shared_data *shared_data)
{
	int	i;

	i = 0;
	shared_data->fork = malloc(sizeof(pthread_mutex_t) * shared_data->number_of_philosophers);
	if (!shared_data->fork)
		return (0);
	while (i < shared_data->number_of_philosophers)
	{
		if (pthread_mutex_init(&shared_data->fork[i], NULL) != 0)
		{
			print_error("Pthread_mutex_init() is failed\n");
			return (free(shared_data->fork), 0);
		}
		// if (pthread_mutex_init(&philo_arr[i].private_mutex, NULL) != 0)
		// {
		// 	print_error("Pthread_mutex_init() is failed\n");
		// 	return (free(shared_data->fork), 0);
		// }
			i++;
	}
	if (pthread_mutex_init(&shared_data->print, NULL) != 0
		|| pthread_mutex_init(&shared_data->meal, NULL) != 0
		|| pthread_mutex_init(&shared_data->stop_check, NULL) != 0)
	{
		print_error("Pthread_mutex_init() is failed\n");
		return (free(shared_data->fork), 0);
	}
	return (1);
}

//Joins philo's threads and  monitor_thread thread -- will be called in init_threads_mutex_philo()
int	join_threads(t_shared_data *shared_data)
{
	int	i;

	i = 0;
	while (i < shared_data->number_of_philosophers)
	{
		if (pthread_join(shared_data->thread_arr[i], NULL) != 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// Creates threads, philo's array and monitor_thread (a seperated thread for monitor_threading others threads) --it will be called in init_threads_mutex_philo()
int	create_threads(t_shared_data *shared_data)
{
	t_philo *philo_arr;
	int	i;

	philo_arr = shared_data->philo_arr;
	i = 0;
	shared_data->thread_arr = malloc(sizeof(pthread_t) * shared_data->number_of_philosophers);
	if (shared_data->thread_arr == NULL)
		return (0);
	while (i < shared_data->number_of_philosophers)
	{
		if (pthread_create(&philo_arr->shared_data->thread_arr[i], NULL, (void *)routine, (void *)&philo_arr[i]) != 0)
		{
			if (join_thread_cleanup(shared_data, 1) == 0)
			{
				print_error("Pthread_join() is failed\n");
				return (0);
			}
		}
		i++;
	}
	return (1);
}

// void	init_mutex_create_threads(t_shared_data *shared_data, t_philo *philo_arr)
// {
// 	if (init_mutexes(shared_data, philo_arr) == 0)
// 		{
// 				print_error("Pthread_mutex_init() is failed\n");
// 				return ;
// 		}
// 	if (create_threads(shared_data, philo_arr) == 0)
// 	{
// 		print_error("Pthread_create() is failed\n");
// 		return ;
// 	}
// 	if (join_threads(philo_arr) == 0)
// 	{
// 		print_error("Pthread_join() is failed\n");
// 		free_all(shared_data);
// 		return ;
// 	}
// }

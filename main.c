#include "philo.h"

//number_of_philosophers~~time_to_die~~time_to_eat~~time_to_sleep
int main(int argc, char **argv)
{
	t_shared_data	shared_data;
	t_philo *philo_arr;

	if (check_validation_and_init_arguments(&shared_data, argc, argv) == 0)
		return (print_error("Input validation is failed\n"), 0);
	philo_arr = init_philo_arr(&shared_data);
	if (philo_arr == NULL)
		return (print_error("Philo_arr creation is failed\n"), 0);
	init_mutexes(&shared_data, philo_arr);
	create_threads(&shared_data, philo_arr);
	//init_mutex_create_threads(&shared_data, philo_arr);
	if (check_philo_arr(&shared_data, philo_arr) == 1)
	{
		join_threads(philo_arr);
		destroy_mutexes(&shared_data);
		free_all(&shared_data);
	}
	return (0);
}

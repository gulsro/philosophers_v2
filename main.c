#include "philo.h"

//number_of_philosophers~~time_to_die~~time_to_eat~~time_to_sleep
int main(int argc, char **argv)
{
	t_shared_data	shared_data;
	t_philo *philo_arr;

	if (check_validation_and_init_arguments(&shared_data, argc, argv) == 0)
	{
		print_error("Input validation is failed\n");
		return (0);
	}
	philo_arr = init_philo_arr(&shared_data);
	if (philo_arr == NULL)
	{
		print_error("Philo_arr creation is failed\n");
		return (0);
	}
	init_mutex_create_threads(&shared_data, philo_arr);
	destroy_mutexes(&shared_data);
	free_all(&shared_data);
	return (0);
}

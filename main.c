#include "philo.h"

//number_of_philosophers~~time_to_die~~time_to_eat~~time_to_sleep
int main(int argc, char **argv)
{
	t_shared_data	shared_data;

	if (check_validation_and_init_arguments(&shared_data, argc, argv) == 0)
		return (print_error("Input validation is failed\n"), 0);
	shared_data.philo_arr = init_philo_arr(&shared_data);
	if (shared_data.philo_arr == NULL)
		return (print_error("Philo_arr creation is failed\n"), 0);
	init_mutexes(&shared_data);
	if (create_threads(&shared_data) == 0)
		return (0);
	check_routine(&shared_data);

	//init_mutex_create_threads(&shared_data, philo_arr);
		// join_threads(philo_arr);
		// destroy_mutexes(&shared_data);
	join_threads(&shared_data);
	destroy_mutexes(&shared_data);
	free_all(&shared_data);
	return (0);
}
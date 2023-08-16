#include "philo.h"

// void leakss()
// {
// 	system("leaks philo");
// }

int	main(int argc, char **argv)
{
	t_shared_data	shared_data;

	//atexit(leakss);
	if (check_validation_and_init_arguments(&shared_data, argc, argv) == 0)
		return (print_error("Input validation is failed\n"), 0);
	shared_data.philo_arr = init_philo_arr(&shared_data);
	if (shared_data.philo_arr == NULL)
		return (print_error("Philo_arr creation is failed\n"), 0);
	init_mutexes(&shared_data);
	if (create_threads(&shared_data) == 0)
		return (0);
	check_routine(&shared_data);
	join_threads(&shared_data);
	destroy_mutexes(&shared_data);
	free_all(&shared_data);
	return (0);
}

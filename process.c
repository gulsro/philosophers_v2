#include "philo.h"

void *routine(void *arg) //ADD LAST NUMBER??
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 1)
		usleep(philo->shared_data->time_to_eat * 1000);
	while (check_simulation_ends(philo->shared_data) == 0
		&& philo->must_eat != 0)
	{
		thread_safe_print("is thinking", philo);
		eating(philo);
		sleeping(philo);

	}
	return (NULL);
}

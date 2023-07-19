#include "philo.h"

int	odd_philo_id_routine(t_philo *philo)
{
	while (1)
	{
		thinking(philo);
		taking_forks(philo);

		if (eating(philo) == 1)
			return 1;

		if (sleeping(philo) == 1)
			return 1;
	}
	return 0;
}


int	even_philo_id_routine(t_philo *philo)
{
	while (1)
	{
		taking_forks(philo);

		if (eating(philo) == 1)
			return 1;

		if (sleeping(philo) == 1)
			return 1;

		thinking(philo);
	}
	return 0;
}

void *routine(void *arg) //ADD LAST NUMBER??
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 1)
		usleep(50);
	if (philo->id == philo->shared_data->number_of_philosophers)
		odd_philo_id_routine(philo);
	if (philo->id % 2 == 1 && philo->id != philo->shared_data->number_of_philosophers)
		odd_philo_id_routine(philo);
	else
		even_philo_id_routine(philo);

	return NULL;
}




	// while (1)
	// {
	// 	taking_forks(philo);

	// 	if (eating(philo) == 1)
	// 		break ;

	// 	if (sleeping(philo) == 1)
	// 		break ;

	// 	thinking(philo);
	// }
	// return NULL;
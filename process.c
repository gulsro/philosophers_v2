#include "philo.h"

// int	odd_philo_id_routine(t_philo *philo)
// {
// 	while (1)
// 	{
// 		thinking(philo);
// 		taking_forks(philo);

// 		if (eating(philo) == 1)
// 			return 1;

// 		if (sleeping(philo) == 1)
// 			return 1;
// 	}
// 	return 0;
// }


// int	even_philo_id_routine(t_philo *philo)
// {
// 	while (1)
// 	{
// 		taking_forks(philo);

// 		if (eating(philo) == 1)
// 			return 1;

// 		if (sleeping(philo) == 1)
// 			return 1;

// 		thinking(philo);
// 	}
// 	return 0;
// }

void *routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	// if (philo->id % 2 == 1)
	// 	usleep(50);
	while (1)
	{
		taking_forks(philo);

		if (eating(philo) == 1)
			return NULL;

		if (sleeping(philo) == 1)
			return NULL;

		thinking(philo);
	}
	return NULL;
}

	// // if (philo->id % 2 == 1)
	// // 	usleep(50);
	// if (philo->id % 2 == 1)
	// 	odd_philo_id_routine(philo);
	// else
	// 	even_philo_id_routine(philo);

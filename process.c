#include "philo.h"

void *routine(void *arg) //ADD LAST NUMBER??
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 1)
		usleep(philo->shared_data->time_to_eat * 1000);
	while (check_simulation_ends(philo->shared_data) != 1
		&& philo->eaten_meals != philo->shared_data->must_eat)
	{
		thread_safe_print("is thinking", philo);
		eating(philo);
		sleeping(philo);
	}
	return NULL;
}


// void	*life(void *tmp)
// {
// 	t_philo			*philo;

// 	philo = tmp;
// 	if (philo->id % 2 == 0)
// 		usleep(philo->tools->time_e * 1000);
// 	while (!check_end(philo->tools) && philo->c_meals != 0)
// 	{
// 		print_lock("is thinking 🤔", philo->id, philo->tools,
// 			elapsed(philo->tools->start_time));
// 		ft_eat(philo);
// 		print_lock("is sleeping 💤", philo->id, philo->tools,
// 			elapsed(philo->tools->start_time));
// 		ft_sleep(philo->tools->time_s);
// 	}
// 	return (NULL);
// }
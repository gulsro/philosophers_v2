#include "philo.h"

long	get_current_time(void)
{
	struct timeval tv;
	long    time;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

long	elapsed_time(long start_time)
{
	long	current;
	long	elapsed_time;

	current = get_current_time();
	elapsed_time = current - start_time;
	return (elapsed_time);
}

int	sleep_tight(long time, t_philo *philo)
{
	long start_time;

	start_time = get_current_time();
	//pthread_mutex_lock(&philo->shared_data->meal);
	while (get_current_time() - start_time <= time)
	{
		//pthread_mutex_lock(&philo->shared_data->meal);
		if (check_simulation_ends(philo) == 1)
		{
			//printf("KIJKKKK\n");
			//pthread_mutex_unlock(&philo->shared_data->meal);
			return (ERROR) ;
		}
		//pthread_mutex_unlock(&philo->shared_data->meal);
		usleep(1000);
	}
	//printf("KIJKKKK\n");
	return (SUCCESS);
	//pthread_mutex_unlock(&philo->shared_data->meal);
}
// 	long milisec;

// 	milisec = time * 1000;
// 	usleep(milisec);
// }

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

void	sleep_tight(long time)
{
	long start_time;

	start_time = get_current_time();
	while (get_current_time() - start_time < time)
		usleep(time * 1000);
}


// void	ft_sleep(int time)
// {
// 	long	start;
// 	long	elapsed;

// 	start = find_ms();
// 	elapsed = 0;
// 	while (elapsed < time)
// 	{
// 		usleep(time * 1000);
// 		elapsed = find_ms() - start;
// 	}
// }


#include "philo.h"

void thread_safe_print(char *print_msg, t_philo *philo)
{
	int checker;

	pthread_mutex_lock(&philo->shared_data->stop_check);
	checker = philo->shared_data->stop_simulation;
	pthread_mutex_unlock(&philo->shared_data->stop_check);
	pthread_mutex_lock(&philo->shared_data->print);
	if (checker == 0)
		printf("%ld %d %s\n", elapsed_time(philo->start_time), philo->id, print_msg);
	pthread_mutex_unlock(&philo->shared_data->print);
}

long	last_meal_time(t_philo *philo)
{
	long	last_meal_time;
	pthread_mutex_lock(&philo->shared_data->meal);
	last_meal_time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->shared_data->meal);
	return (last_meal_time);
}

void	set_meal_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->shared_data->meal);
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(&philo->shared_data->meal);
}

int stop_simulation(t_shared_data *shared_data)
{
	pthread_mutex_lock(&shared_data->stop_check);
	shared_data->stop_simulation = 1;
	pthread_mutex_unlock(&shared_data->stop_check);
	return (1);
}

int	ft_atoi(char *str)
{
	int				i;
	long long int	n;

	i = 0;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	if (n > INT_MAX)
	{
		print_error("Number of the philos are greater than INT_MAX");
		return (0);
	}
	return ((int)(n));
}

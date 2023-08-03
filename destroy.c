#include "philo.h"

void	free_all(t_shared_data *shared_data)
{
	free(shared_data->thread_arr); // not correct dealloc whole array
	free(shared_data->fork); //same here
}

/*This funtion joins threads and does clean-up in case of an error during creation of threads.
 * Second parameter is a flag for indicating if create_thread() fails at array of philo threads or after single monitor thread.
thread_array_flag = 1 >> Function joins with created threads in the array
thread_array_flag = 0 >> Function joins all threads (array and also single monitor thread)
*/
int	join_thread_cleanup(t_shared_data *shared_data, int thread_array_flag)
{
	int	i;

	i = 0;
	if (thread_array_flag == 1)
	{
		while (i >= 0)
		{
			if (pthread_join(shared_data->thread_arr[i], NULL) != 0)
			{
				free_all(shared_data);
				return (0);
			}
			i--;
		}
	}
	if (thread_array_flag == 0)
	{
		while (i < shared_data->number_of_philosophers)
		{
			if (pthread_join(shared_data->thread_arr[i], NULL) != 0)
			{
				free_all(shared_data);
				return 0;
			}
			i++;
		}
	}
	free_all(shared_data);
	return (1);
}

void	destroy_mutexes(t_shared_data *shared_data)
{
	int	i;

	i = 0;
	while (i < shared_data->number_of_philosophers)
	{
		if (pthread_mutex_destroy(&shared_data->fork[i]) != 0)
		{
			printf("FORK\n");
			return ;
		}
		i++;
	}
	if (pthread_mutex_destroy(&shared_data->print) != 0)
	{
		printf("PRINT\n");
		return ;
	}
	if (pthread_mutex_destroy(&shared_data->meal) != 0)
	{
		printf("MEAL\n");
		return ;
	}
}



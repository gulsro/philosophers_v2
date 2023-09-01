/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   destroy.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/24 14:03:14 by gozturk       #+#    #+#                 */
/*   Updated: 2023/08/24 14:03:18 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_shared_data *shared_data)
{
	free(shared_data->philo_arr);
	free(shared_data->thread_arr);
	free(shared_data->fork);
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
	if (pthread_mutex_destroy(&shared_data->print) != 0
		|| pthread_mutex_destroy(&shared_data->meal) != 0
		|| pthread_mutex_destroy(&shared_data->stop_check) != 0
		|| pthread_mutex_destroy(&shared_data->create) != 0)
	{
		printf("pthread_mutex_destroy failed\n");
		return ;
	}
}

void	detach_threads(pthread_t *thread_arr, int i)
{
	while (i >= 0)
	{
		if (pthread_join(thread_arr[i], NULL) != 0)
			return ;
		i--;
	}
}

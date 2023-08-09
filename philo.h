/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/07 12:33:19 by gozturk       #+#    #+#                 */
/*   Updated: 2023/06/16 17:17:28 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

# define ERROR 1
# define SUCCESS 0

# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_philo
{
	int	id;
	int	number_of_philosophers;
	long	start_time;
	long	last_meal_time;
	int	dead;
	int must_eat;
	//pthread_mutex_t private_mutex;
	struct s_shared_data *shared_data;
}t_philo;

typedef struct s_shared_data
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
	int	stop_simulation;
	int philos_are_full;
	t_philo *philo_arr;
	pthread_t	*thread_arr;
	pthread_mutex_t	*fork;
	pthread_mutex_t print;
	pthread_mutex_t meal;
	pthread_mutex_t stop_check;
}t_shared_data;

//time.c
long	get_current_time(void);
long	elapsed_time(long start_time);
void	sleep_tight(long time);

//input_validation.c
int		check_validation_and_init_arguments(t_shared_data *shared_data, int argc, char **argv);
void    init_arguments(t_shared_data *shared_data, int argc, char **argv);

//utils.c
void thread_safe_print(char *print_msg, t_philo *philo);
int	ft_atoi(char *str);
void	set_meal_time(t_philo *philo);
long	last_meal_time(t_philo *philo);
int stop_simulation(t_shared_data *shared_data);
void set_meal_number(t_philo *philo);



//error.c
void    print_error(char *msg);

//init.c
t_philo	*init_philo_arr(t_shared_data *shared_data);
//void    init_mutex_create_threads(t_shared_data *shared_data, t_philo *philo_arr);
int	init_mutexes(t_shared_data *shared_data);
int	join_threads(t_shared_data *shared_data);
int	create_threads(t_shared_data *shared_data);


//actions.c
//void    taking_forks(t_philo *philo);
void    eating(t_philo *philo);
void    thinking(t_philo *philo);
void    sleeping(t_philo *philo);

//destroy.c
void    free_all(t_shared_data *shared_data);
int join_thread_cleanup(t_shared_data *shared_data, int thread_array_flag);
void    destroy_mutexes(t_shared_data *shared_data);

//check_life_circle.c
int check_simulation_ends(t_shared_data *shared_data);
// int check_philo_tummy_full(t_philo *philo);
// int check_all_philos_done_eating(t_philo *philo);
int	check_starvation(t_shared_data *shared_data);
int check_meals_done(t_shared_data *shared_data);
void check_routine(t_shared_data *shared_data);


//process.c
int	even_philo_id_routine(t_philo *philo);
int	odd_philo_id_routine(t_philo *philo);
void    *routine(void *arg);

#endif

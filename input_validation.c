#include "philo.h"

static	int	ft_isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}

//This function checks if each character in the argument is a digit. it checks char by char so you dont need to check '-' in ft_atoi 
static int	check_all_digit(char **argv)
{
	int	i_argv;
	int	i;

	i_argv = 1;
	while (argv[i_argv])
	{
		i = 0;
		while (argv[i_argv][i])
		{
			if (ft_isdigit(argv[i_argv][i]) == 1)
				i++;
			else
				return (0);
		}
		i_argv++;
	}
	return (1);
}

// Initializes command line arguments, will be called in check__validation_and_init_arguments()
void    init_arguments(t_shared_data *shared_data, int argc, char **argv)
{
    shared_data->number_of_philosophers = ft_atoi(argv[1]);
    shared_data->time_to_die = ft_atoi(argv[2]);
    shared_data->time_to_eat = ft_atoi(argv[3]);
    shared_data->time_to_sleep = ft_atoi(argv[4]);
	shared_data->stop_simulation = 0;
    if (argc == 6)
        shared_data->must_eat = ft_atoi(argv[5]);
    else
    	shared_data->must_eat = -1;
}


//This funtion checks if given arguments are digit, is so, inits arguments
int check_validation_and_init_arguments(t_shared_data *shared_data, int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		print_error("Wrong number of arguments\n");
		return (0);
	}
	if (check_all_digit(argv) == 0)
	{
		print_error("One or more given arguments are in wrong format\n");
		return (0);
	}
	init_arguments(shared_data, argc, argv);
	if (shared_data->number_of_philosophers < 1)
	{
		print_error("There should be at least one philosopher\n");
		return (0);
	}
	return (1);
}

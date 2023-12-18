cd philo

# Compile 
make

# Run the program with number_of_philosophers, time_to_die, time_to_eat, time_to_sleep, [number_of_times_each_philosopher_must_eat (optional argument)]
./philo 5 800 200 200 7

# Remove objects
make clean

# Remove objects and executable
make fclean

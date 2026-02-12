#include "philo.h"

void	init_god(t_god *god, t_philo *philos, mutex *forks)
{
	god->forks = forks;
	god->philos = philos;
	if (pthread_mutex_init(&god->write_lock, NULL) != 0
		|| pthread_mutex_init(&god->spag_lock, NULL) != 0)
		kill_philos(god, "[Mutex Init ERROR]\n", -1, 1);
}

void	init_philos(t_god *god, t_philo *philos, mutex *forks, char **argv)
{
	int	i;

	i = -1;
	while (++i < atoi(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].times.to_die = atoi(argv[2]);
		philos[i].times.to_eat = atoi(argv[3]);
		philos[i].times.to_sleep = atoi(argv[4]);
		philos[i].times.from_last_meal = get_current_time();
		philos[i].times.from_born = get_current_time();
		philos[i].must_eat = -1;
		if (argv[5])
			philos[i].must_eat = atoi(argv[5]);
		philos[i].meals_eaten = 0;
		philos[i].philo_count = atoi(argv[1]);
		philos[i].mutexes.left_fork = &forks[i];
		if (i == 0)
			philos[i].mutexes.right_fork = &forks[philos[i].philo_count - 1];
		else
			philos[i].mutexes.right_fork = &forks[i - 1];
		philos[i].mutexes.write_lock = &god->write_lock;
		philos[i].mutexes.spag_lock = &god->spag_lock;
	}
}

void	init_forks(t_god *god, mutex *forks, int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			kill_philos(god, "[Mutex Init ERROR]\n", i, 1);
	}
}

void arg_check(int argc, char **argv)
{
    int i;
    long num;

    i = 0;
    if (argc != 5 && argc != 6)
        error_message("[Invalid number of arguements]\n", 1);
    while (++i < argc)
	{
		num = atoi(argv[i]);
		if (i == 1 && (num < 1 || num > MAX_PHILOS))
			error_message("[Argument ERROR]\n", 1);
		else if (i == 5 && (num < 0 || num > INT_MAX))
			error_message("[Argument ERROR]\n", 1);
		else if (i != 1 && i != 5 && (num < 1 || num > INT_MAX))
			error_message("[Argument ERROR]\n", 1);
	}
}

int main(int argc, char **argv)
{
    t_philo     philos[MAX_PHILOS];
    mutex   forks[MAX_PHILOS];
    t_god   god;

    arg_check(argc, argv);
    init_god(&god, philos, forks);
    init_forks(&god, forks, atoi(argv[1]));
    init_philos(&god, philos, forks, argv);
    start_earth(&god, philos[0].philo_count);
    kill_philos(&god, NULL, philos[0].philo_count, 0);
    return (0);
}
#include "philo.h"

bool	is_all_eat(t_philo *philos)
{
	int		finished;
	int		i;

	i = -1;
	finished = 0;
	if (philos[0].must_eat == -1)
		return (false);
	while (++i < philos[0].philo_count)
	{
		pthread_mutex_lock(philos->mutexes.spag_lock);
		if (philos[i].meals_eaten >= philos[i].must_eat)
			++finished;
		pthread_mutex_unlock(philos->mutexes.spag_lock);
	}
	if (finished == philos[0].philo_count)
	{
		pthread_mutex_lock(philos->mutexes.write_lock);
		return (true);
	}
	return (false);
}

void	*obs(void *ptr)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)ptr;
	while (true)
	{
		i = -1;
		while (++i < philos[0].philo_count)
		{
			pthread_mutex_lock(philos->mutexes.spag_lock);
			if (get_current_time() - philos[i].times.from_last_meal
				> philos[i].times.to_die)
			{
				pthread_mutex_unlock(philos->mutexes.spag_lock);
				print_action(&philos[i], RED" died"RESET);
				pthread_mutex_lock(philos->mutexes.write_lock);
				return (NULL);
			}
			pthread_mutex_unlock(philos->mutexes.spag_lock);
		}
		if (is_all_eat(philos))
			return (NULL);
	}
	return (NULL);
}

void	philo_action(t_philo *philo)
{
	pthread_mutex_lock(philo->mutexes.left_fork);
	print_action(philo, " has taken a fork");
	pthread_mutex_lock(philo->mutexes.right_fork);
	print_action(philo, " has taken a fork");
	pthread_mutex_lock(philo->mutexes.spag_lock);
	print_action(philo, " is eating");
	philo->times.from_last_meal = get_current_time();
	philo->meals_eaten += 1;
	pthread_mutex_unlock(philo->mutexes.spag_lock);
	ft_usleep(philo->times.to_eat);
	pthread_mutex_unlock(philo->mutexes.left_fork);
	pthread_mutex_unlock(philo->mutexes.right_fork);
	print_action(philo, " is sleeping");
	ft_usleep(philo->times.to_sleep);
	print_action(philo, " is thinking");
}


void	*start_simulation(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	pthread_mutex_lock(philo->mutexes.spag_lock);
	philo->times.from_born = get_current_time();
	philo->times.from_last_meal = get_current_time();
	pthread_mutex_unlock(philo->mutexes.spag_lock);
	while (true)
		philo_action(philo);
	return (NULL);
}

void start_earth(t_god *god, int count)
{
    pthread_t obs_id;
    int i;

    i = -1;
	if (pthread_create(&obs_id, NULL, &obs, god->philos) != 0)
		kill_philos(god, "[Thread Creation ERROR]\n", count, 1);
	while (++i < count)
	{
		if (pthread_create(&god->philos[i].thread_id, NULL,
				start_simulation, &god->philos[i]) != 0)
			kill_philos(god, "[Thread Creation ERROR]\n", count, 1);
	}
	i = -1;
	if (pthread_join(obs_id, NULL) != 0)
		kill_philos(god, "[Thread Join ERROR]\n", count, 1);
	while (++i < count)
	{
		if (pthread_detach(god->philos[i].thread_id) != 0)
			kill_philos(god, "[Thread Detach ERROR]\n", count, 1);
	}
}
#ifndef PHILO_H
# define PHILO_H

# include <stdbool.h>
# include <pthread.h>
# include <limits.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h> //remove later

# define MAX_PHILOS 300

# define YELLOW     "\033[33m"
# define RED        "\033[31m"
# define RESET      "\033[0m"

typedef pthread_mutex_t	mutex;
typedef struct timeval	t_timeval;


typedef struct s_mutexes
{
    mutex *left_fork;
    mutex *right_fork;
    mutex *write_lock;
    mutex *spag_lock;

} t_mutexes;

typedef struct s_times
{
    size_t to_die;
    size_t to_eat;
    size_t to_sleep;
    size_t from_last_meal;
    size_t from_born;
} t_times;

typedef struct s_philo
{
    int id;
    int must_eat;
    int meals_eaten;
    int philo_count;
    pthread_t thread_id;
    t_times times;
    t_mutexes mutexes;
} t_philo;

typedef struct s_god
{
    mutex write_lock;
    mutex spag_lock;
    mutex *forks;
    t_philo *philos;

} t_god;

//utils
void	error_message(char *text, int signal);
void	kill_philos(t_god *god, char *str, int count, int signal);
void	print_action(t_philo *philo, char *action);
size_t	get_current_time(void);
void	ft_usleep(size_t mls);

//start
bool	is_all_eat(t_philo *philos);
void	*obs(void *ptr);
void	philo_action(t_philo *philo);
void	*start_simulation(void *ptr);
void start_earth(t_god *god, int count);

#endif
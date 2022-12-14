/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:33:32 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/14 17:57:53 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ---------- Includes ---------- */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdarg.h>

/* ---------- Macros ---------- */
# define SUCCESS 0
# define FAILURE 1
/* --- Error codes --- */
# define NARGERR -1
# define ARGERR -2
# define MALLOCERR -3
# define THREADERR -4
/* --- Actions --- */
# define T_FORK 3
# define EATING 4
# define SLEEPING 5
# define THINKING 6
# define DIED 7
# define FINISHED 8

/* ---------- Structs ---------- */
typedef struct s_philo
{
	size_t			index;
	size_t			lfork;
	size_t			rfork;
	size_t			meals;
	size_t			last_meal;
	size_t			survive;
	struct s_main	*main;
}	t_philo;

typedef struct s_arg
{
	size_t	nphilo;
	size_t	tdie;
	size_t	teat;
	size_t	tsleep;
	size_t	nmeals;
	size_t	*forks;
}	t_arg;

typedef struct s_mutex
{
	pthread_mutex_t	*mforks;
	pthread_mutex_t	state;
	pthread_mutex_t	texit;
	pthread_mutex_t	over;
}	t_mutex;

typedef struct s_main
{
	struct s_arg	arg;
	struct s_philo	*philos;
	struct s_mutex	mutexes;
	pthread_t		*tid;
	size_t			over;
	size_t			exit;
	size_t			start;
}	t_main;

/* ---------- Prototypes ---------- */
int	sleep_think(t_philo *philo);
int	eat(t_philo *philo);
int	destroy(t_main *main);
int	launch(t_main *main);
int	ft_atol(char *str, size_t *arg);
int	ft_errors(int err);
int	initialize(int ac, char **av, t_main *main);
int	is_dead(t_philo *philo);
int	is_over(t_philo *philo);
size_t	ptime(void);
void	*routine(void *arg);
void	state(t_philo *philo, size_t timestamp, int action);
void	waiting(size_t ms);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:02:50 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/13 17:31:47 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdarg.h>
# include <semaphore.h>

/* ------------ Macros ------------- */
# define SUCCESS 0
# define FAILURE 1
/* --- Error codes --- */
# define N_ARGS -1
# define ARGS -2
# define MALLOC -3
# define THREAD_ERR -4
/* --- Actions --- */
# define T_FORK 3
# define EATING 4
# define SLEEPING 5
# define THINKING 6
# define DIED 7
# define FINISHED 8

/* ------------ Structs ------------- */
typedef struct s_philo
{
	size_t			index;
	size_t			l_fork;
	size_t			r_fork;
	size_t			meals;
	size_t			last_meal;
	size_t			survive;
	struct s_main	*main;
}	t_philo;

typedef struct s_args
{
	size_t	n_philo;
	size_t	t_die;
	size_t	t_eat;
	size_t	t_sleep;
	size_t	nt_ph_eat;
	size_t	*forks;
}	t_args;

typedef struct s_main
{
	struct s_args	args;
	struct s_philo	*philos;
	pthread_t		*tid;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	state;
	pthread_mutex_t	finished;
	size_t			over;
	size_t			exit;
}	t_main;

/* ------------ Libft ------------- */
int		ft_errors(int err);
int		ft_atol(char *str, size_t *arg);


#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:19:01 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/14 18:00:14 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	pick_fork(t_philo *philo, int i)
{
	size_t	fork;

	if (i != 0)
		fork = philo->rfork;
	else
		fork = philo->lfork;
	return (fork);
}

int	take_fork(t_philo *philo)
{
	int		i;
	size_t	fork;

	i = 0;
	while (i < 2)
	{
		if (is_dead(philo))
			return (FAILURE);
		fork = pick_fork(philo, i);
		pthread_mutex_lock(philo->main->mutexes.mforks + fork);
		if (philo->main->arg.forks[fork])
		{
			state(philo, ptime() - philo->main->start, T_FORK);
			philo->main->arg.forks[fork] = 0;
			i++;
		}
		pthread_mutex_unlock(philo->main->mutexes.mforks + fork);
	}
	return (SUCCESS);
}

int	put_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->main->mutexes.mforks + philo->lfork);
	philo->main->arg.forks[philo->lfork] = 1;
	pthread_mutex_unlock(philo->main->mutexes.mforks + philo->lfork);
	pthread_mutex_lock(philo->main->mutexes.mforks + philo->rfork);
	philo->main->arg.forks[philo->rfork] = 1;
	pthread_mutex_unlock(philo->main->mutexes.mforks + philo->rfork);
	if (philo->main->arg.nmeals
		&& philo->main->arg.nmeals == philo->meals)
	{
		state(philo, ptime() - philo->main->start, FINISHED);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	eat(t_philo *philo)
{
	if (take_fork(philo))
		return (FAILURE);
	philo->last_meal = ptime();
	state(philo, philo->last_meal - philo->main->start, EATING);
	waiting(philo->main->arg.teat);
	philo->survive = philo->last_meal + philo->main->arg.tdie;
	philo->meals++;
	if (put_fork(philo))
		return (FAILURE);
	return (SUCCESS);
}

int	sleep_think(t_philo *philo)
{
	if (is_over(philo))
		return (FAILURE);
	state(philo, philo->last_meal + philo->main->arg.teat - philo->main->start, SLEEPING);
	waiting(philo->main->arg.tsleep);
	if (is_dead(philo) || is_over(philo))
		return (FAILURE);
	state(philo, philo->last_meal + philo->main->arg.teat
		+ philo->main->arg.tsleep - philo->main->start, THINKING);
	return (SUCCESS);
}

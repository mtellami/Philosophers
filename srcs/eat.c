/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:15:45 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/11 10:56:54 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_fork(t_philo *philo)
{
	int i;
	size_t	fork;
	
	i = 0;
	while (i < 2)
	{
		if (is_dead(philo) || philo->done)
			return (FAILURE);
		if (i)
			fork = philo->r_fork;
		else
			fork = philo->l_fork;
	pthread_mutex_lock(philo->main->mutex + fork);
	if (philo->main->args.forks[fork])
	{
		state(philo, current_time(), T_FORK);
		philo->main->args.forks[fork] = 0;
		i++;
	}
	pthread_mutex_unlock(philo->main->mutex + fork);
	}
	return (SUCCESS);
}

int put_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->main->mutex + philo->l_fork);
	philo->main->args.forks[philo->l_fork] = 1;
	pthread_mutex_unlock(philo->main->mutex + philo->l_fork);
	pthread_mutex_lock(philo->main->mutex + philo->r_fork);
	philo->main->args.forks[philo->r_fork] = 1;
	pthread_mutex_unlock(philo->main->mutex + philo->r_fork);
	state(philo, philo->last_meal + philo->main->args.t_eat, SLEEPING);
	waiting(philo->main->args.t_sleep);
	if (is_dead(philo))
		return (FAILURE);
	state(philo, philo->last_meal + philo->main->args.t_eat + philo->main->args.t_sleep, THINKING);
	return (SUCCESS);
}

int eat(t_philo *philo)
{
	philo->eating = 1;
	philo->last_meal = current_time();
	state(philo, philo->last_meal, EATING);
	waiting(philo->main->args.t_eat);
	philo->survive = philo->last_meal + philo->main->args.t_die;
	philo->eating = 0;
	philo->meals++;
	if (philo->main->args.nt_ph_eat > 0 && philo->main->args.nt_ph_eat >= philo->meals)
	{
		pthread_mutex_lock(philo->main->mutex + philo->l_fork);
		philo->main->args.forks[philo->l_fork] = 1;
		pthread_mutex_unlock(philo->main->mutex + philo->l_fork);
		pthread_mutex_lock(philo->main->mutex + philo->r_fork);
		philo->main->args.forks[philo->r_fork] = 1;
		pthread_mutex_unlock(philo->main->mutex + philo->r_fork);
		philo->done = 1;
		return (FAILURE);
	}
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:50:29 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/14 09:57:56 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = ptime();
	philo->survive = philo->last_meal + philo->main->arg.tdie;
	while (1)
	{
		if (eat(philo) || sleep_think(philo))
			break ;
	}
	pthread_mutex_lock(&philo->main->mutexes.texit);
	philo->main->exit++;
	pthread_mutex_unlock(&philo->main->mutexes.texit);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:00 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/12 19:29:13 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->last_meal = current_time();
	philo->survive = philo->last_meal + philo->main->args.t_die;
	while (1)
	{
		if (eat(philo) || sleep_think(philo))
			break ;
	}
	pthread_mutex_lock(&philo->main->finished);
	philo->main->exit++;
	pthread_mutex_unlock(&philo->main->finished);
	return (NULL);
}

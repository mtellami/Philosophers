/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:27:32 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/14 18:06:42 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_philo *philo)
{
	if (ptime() > philo->survive)
	{
		state(philo, philo->survive - philo->main->start, DIED);
		pthread_mutex_lock(&philo->main->mutexes.over);
		philo->main->over = 1;
		pthread_mutex_unlock(&philo->main->mutexes.over);
		return (FAILURE);
	}
	return (SUCCESS);
}

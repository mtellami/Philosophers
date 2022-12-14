/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:33:36 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/14 11:30:20 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	state(t_philo *philo, size_t timestamp, int action)
{
	pthread_mutex_lock(&philo->main->mutexes.state);
	if (philo->main->over == 1)
	{
		pthread_mutex_unlock(&philo->main->mutexes.state);
		return ;
	}
	if (action == T_FORK)
		printf("%zu %zu has taken a fork\n", timestamp, philo->index);
	else if (action == EATING)
		printf("%zu %zu is eating\n", timestamp, philo->index);
	else if (action == SLEEPING)
		printf("%zu %zu is sleeping\n", timestamp, philo->index);
	else if (action == THINKING)
		printf("%zu %zu is thinking\n", timestamp, philo->index);
	else if (action == FINISHED)
		printf("%zu %zu finish his meals\n", timestamp, philo->index);
	else if (action == DIED)
		printf("%zu %zu died\n", timestamp, philo->index);
	pthread_mutex_unlock(&philo->main->mutexes.state);
}

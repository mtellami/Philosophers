/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:18:09 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/12 14:36:22 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	state(t_philo *philo, size_t timestamp, int action)
{
	if (philo->main->over == 1)
		return ;
	pthread_mutex_lock(&philo->main->state);
	if (action == T_FORK)
		printf("%zu %zu has taken a fork\n", timestamp, philo->index);
	else if (action == EATING)
		printf("%zu %zu is eating\n", timestamp, philo->index);
	else if (action == SLEEPING)
		printf("%zu %zu is sleeping\n", timestamp, philo->index);
	else if (action == THINKING)
		printf("%zu %zu is thinking\n", timestamp, philo->index);
	else if (action == DIED)
		printf("%zu %zu died\n", timestamp, philo->index);
	pthread_mutex_unlock(&philo->main->state);
}

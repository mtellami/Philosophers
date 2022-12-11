/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:18:09 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/09 18:43:46 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	state(t_philo *philo, size_t timestamp, int action)
{
	pthread_mutex_lock(&philo->main->state);
	if (action == T_FORK)
		ft_printf(1, "%d %d has taken a fork\n", timestamp, philo->index);
	else if (action == EATING)
		ft_printf(1, "%d %d is eating\n", timestamp, philo->index);
	else if (action == SLEEPING)
		ft_printf(1, "%d %d is sleeping\n", timestamp, philo->index);
	else if (action == THINKING)
		ft_printf(1, "%d %d  is thinking\n", timestamp, philo->index);
	else if (action == DIED)
		ft_printf(1, "%d %d died\n", timestamp, philo->index);
	pthread_mutex_unlock(&philo->main->state);
}

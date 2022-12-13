/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 13:58:47 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/12 16:22:53 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_dead(t_philo *philo)
{
	if (philo->main->over == 1)
		return (FAILURE);
	if (current_time() > philo->survive)
	{
		state(philo, philo->survive, DIED);
		return (FAILURE);
	}
	return (SUCCESS);
}

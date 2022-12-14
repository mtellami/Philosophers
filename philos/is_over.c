/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_over.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:06:40 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/14 12:32:28 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_over(t_philo *philo)
{
	if ((philo->main->arg.nmeals
		&& philo->meals == philo->main->arg.nmeals)
		|| philo->main->over)
		return (FAILURE);
	return (SUCCESS);
}

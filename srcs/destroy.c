/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:40:00 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/10 14:21:21 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	destroy(t_main *main)
{
	size_t	i;

	i = 0;
	while (i < main->args.n_philo)
	{
		pthread_mutex_destroy(main->mutex + i);
		i++;
	}
	pthread_mutex_destroy(&main->state);
	return (SUCCESS);
}

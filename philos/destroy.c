/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:03:59 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/14 11:20:41 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	destroy(t_main *main)
{
	size_t	i;

	i = 0;
	while (i < main->arg.nphilo)
	{
		pthread_mutex_destroy(main->mutexes.mforks + i);
		i++;
	}
	pthread_mutex_destroy(&main->mutexes.state);
	pthread_mutex_destroy(&main->mutexes.texit);
	pthread_mutex_destroy(&main->mutexes.over);
	return (SUCCESS);
}

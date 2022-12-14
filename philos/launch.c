/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:48:18 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/14 18:36:17 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	launch(t_main *main)
{
	size_t	i;

	i = 0;
	while (i < main->arg.nphilo)
	{
		main->start = ptime();
		if (pthread_create(main->tid + i, NULL, &routine, main->philos + i))
			return (ft_errors(THREADERR));
		pthread_detach(main->tid[i]);
		i++;
	}
	return (SUCCESS);
}

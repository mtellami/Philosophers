/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:55:22 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/12 12:11:02 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	launch(t_main *main)
{
	size_t	i;

	i = 0;
	while (i < main->args.n_philo)
	{
		if (pthread_create(main->tid + i, NULL, &routine, main->philos + i))
			return (ft_errors(THREAD_ERR));
		pthread_detach(main->tid[i]);
		i++;
	}
	return (SUCCESS);
}

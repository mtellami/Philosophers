/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:49:19 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/19 03:57:21 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	waitproccess(t_main *main)
{
	size_t	i;

	i = 0;
	while (i < main->args.n_philo)
		waitpid(main->philos[i++].pid, NULL, 0);
	sem_post(main->semaphores.die);
}

int	launch(t_main *main)
{
	size_t		i;

	i = 0;
	sem_wait(main->semaphores.die);
	while (i < main->args.n_philo)
	{
		main->philos[i].pid = fork();
		if (main->philos[i].pid == 0)
		{
			routine(&main->philos[i]);
			exit(SUCCESS);
		}
		i++;
	}
	if (main->args.nt_ph_eat)
		waitproccess(main);
	return (SUCCESS);
}

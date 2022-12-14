/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:30:53 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/14 15:26:09 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_init(int ac, char **av, t_main *main)
{
	size_t	i;

	if (ft_atol(av[1], &main->arg.nphilo)
		|| ft_atol(av[2], &main->arg.tdie)
		|| ft_atol(av[3], &main->arg.teat)
		|| ft_atol(av[4], &main->arg.tsleep))
		return (ft_errors(ARGERR));
	if (ac == 6 && ft_atol(av[5], &main->arg.nmeals))
		return (ft_errors(ARGERR));
	else if (ac == 5)
		main->arg.nmeals = 0;
	main->arg.forks = malloc(sizeof(size_t) * main->arg.nphilo);
	if (!main->arg.forks)
		return (ft_errors(MALLOCERR));
	i = 0;
	while (i < main->arg.nphilo)
		main->arg.forks[i++] = 1;
	main->over = 0;
	main->exit = 0;
	return (SUCCESS);
}

int	philos_init(t_main *main)
{
	size_t	i;

	main->philos = malloc(sizeof(t_philo) * main->arg.nphilo);
	main->tid = malloc(sizeof(pthread_t) * main->arg.nphilo);
	if (!main->philos || !main->tid)
		return (ft_errors(MALLOCERR));
	i = 0;
	while (i < main->arg.nphilo)
	{
		main->philos[i].index = i + 1;
		main->philos[i].lfork = i;
		main->philos[i].rfork = (i + 1) % main->arg.nphilo;
		main->philos[i].meals = 0;
		main->philos[i].main = main;
		i++;
	}
	return (SUCCESS);
}

int	mutex_init(t_main *main)
{
	size_t	i;

	main->mutexes.mforks = malloc(sizeof(pthread_mutex_t) * main->arg.nphilo);
	if (!main->mutexes.mforks)
		return (ft_errors(MALLOCERR));
	i = 0;
	while (i < main->arg.nphilo)
		pthread_mutex_init(main->mutexes.mforks + i++, NULL);
	pthread_mutex_init(&main->mutexes.state, NULL);
	pthread_mutex_init(&main->mutexes.texit, NULL);
	pthread_mutex_init(&main->mutexes.over, NULL);
	return (SUCCESS);
}

int	initialize(int ac, char **av, t_main *main)
{
	if (arg_init(ac, av, main))
		return (FAILURE);
	if (philos_init(main))
		return (FAILURE);
	if (mutex_init(main))
		return (FAILURE);
	return (SUCCESS);
}

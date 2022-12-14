/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 07:33:34 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/14 11:54:14 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_main	main;

	if (ac != 5 && ac != 6)
		return (ft_errors(NARGERR));
	if (initialize(ac, av, &main))
		return (FAILURE);
	if (launch(&main))
		return (FAILURE);
	while (1)
		if (main.exit == main.arg.nphilo)
			break;
	destroy(&main);
	return (FAILURE);
}

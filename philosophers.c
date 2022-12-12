/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:07:36 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/12 15:30:31 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_main	main;

	if (ac != 5 && ac != 6)
		return (ft_errors(N_ARGS));
	if (initialize(ac, av, &main))
		return (FAILURE);
	if (launch(&main))
		return (FAILURE);
	destroy(&main);
	while (1)
	{
		if (main.exit == main.args.n_philo)
			break ;
	}
	return (SUCCESS);
}

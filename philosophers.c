/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:07:36 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/11 14:30:03 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int ac, char **av)
{
	t_main	main;

	if (ac != 5 && ac != 6)
		return (ft_errors(N_ARGS));
	if (initialize(ac, av, &main))
		return (FAILURE);
	if (launch(&main))
		return (FAILURE);
	destroy(&main);
	pthread_exit (NULL);
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 10:40:16 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/09 18:36:02 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_errors(int err)
{
	if (err == N_ARGS)
		ft_printf(2, "Error : invalid number of arguments\n");
	else if (err == ARGS)
		ft_printf(2, "Error : wrong arguments\n");
	else if (err == MALLOC)
		ft_printf(2, "Error : fail memory allocation\n");
	else if (err == THREAD_ERR)
		ft_printf(2, "Error : fail creating threads");
	return (FAILURE);
}

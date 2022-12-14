/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 08:31:58 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/14 08:35:01 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_errors(int err)
{
	if (err == NARGERR)
		printf("Error : invalid number of arguments\n");
	else if (err == ARGERR)
		printf("Error : wrong arguments\n");
	else if (err == MALLOCERR)
		printf("Error : fail allocate memory\n");
	else if (err == THREADERR)
		printf("Error : fail creating threads\n");
	return (FAILURE);
}

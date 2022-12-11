/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:06:15 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/05 15:25:13 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atol(char *str, size_t *arg)
{
	if (!(*str))
		return (FAILURE);
	*arg = 0;
	while (*str && *str >= '0' && *str <= '9')
		*arg = (*arg * 10) + (*str++ - '0');
	if (*str || !(*arg))
		return (FAILURE);
	return (SUCCESS);
}

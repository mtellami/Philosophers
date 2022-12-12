/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:15:18 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/12 15:34:44 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	waiting(size_t ms)
{
	size_t	date;

	date = current_time() + ms;
	while (current_time() < date)
		usleep(ms / 1000);
}

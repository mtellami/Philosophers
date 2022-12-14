/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptime.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:56:28 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/14 10:00:35 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ptime(void)
{
	static struct timeval	time;
	size_t					now;

	gettimeofday(&time, NULL);
	now = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (now);
}

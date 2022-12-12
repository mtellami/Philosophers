/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   current_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:12:08 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/12 15:34:36 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

size_t	current_time(void)
{
	size_t					now;
	static struct timeval	time;

	gettimeofday(&time, NULL);
	now = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (now);
}

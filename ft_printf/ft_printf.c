/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtellami <mtellami@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:16:44 by mtellami          #+#    #+#             */
/*   Updated: 2022/12/09 18:31:22 by mtellami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_format(int fd, va_list ap, char c)
{
	if (c == 's')
		ft_putstr_fd(fd, va_arg(ap, char *));
	else if (c == 'd')
		ft_putnbr_fd(fd, va_arg(ap, size_t));
	else
		ft_putchar_fd(fd, c);
}

void	ft_printf(int fd, char *str, ...)
{
	va_list	ap;
	
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_format(fd, ap, *str);
		}
		else
			ft_putchar_fd(fd, *str);
		str++;
	}
	va_end(ap);
}

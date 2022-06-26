/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orandan <orandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:19:03 by odan              #+#    #+#             */
/*   Updated: 2022/06/26 11:35:30 by orandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

uli	get_time()
{
	uli	tme_ms;
	clck	tme;

	gettimeofday(&tme, NULL);
	tme_ms = tme.tv_sec * 1000;
	tme_ms += tme.tv_usec / 1000;
	return (tme_ms);
}

int	ft_argtoi(const char *str)
{
	uli	integ;

	integ = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		integ *= 10;
		integ += (*str++ - 48);
		if (integ > 2147483647)
			return (0);
	}
	if ((*str) && (*str < '0' || *str > '9'))
		return (0);
	return ((int)integ);
}

void	ft_usleep(uli tme)
{
	while (tme > 100)
	{
		usleep(75);
		tme -= 100;
	}
	usleep(tme);
}

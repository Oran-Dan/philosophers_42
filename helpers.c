/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orandan <orandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 12:19:03 by odan              #+#    #+#             */
/*   Updated: 2022/06/29 21:55:54 by orandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}

t_uli	get_time(void)
{
	t_uli	tme_ms;
	t_clck	tme;

	gettimeofday(&tme, NULL);
	tme_ms = tme.tv_sec * 1000;
	tme_ms += tme.tv_usec / 1000;
	return (tme_ms);
}

int	ft_argtoi(const char *str)
{
	t_uli	integ;

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

void	ft_msleep(t_uli tme)
{
	t_uli	i;

	i = get_time();
	while (get_time() < i + tme)
		usleep(50);
}

int	meal_chck(t_phil *ph)
{
	t_phil	*tmp;
	
	tmp = ph;
	printf("hello\n");
	while (tmp->nxt != ph)
	{
		if (tmp->n_e)
			return (0);
		tmp = tmp->nxt;
	}
	if (tmp->n_e)
		return (0);
	printf("%i %i %i %i\n", ph->n_ph, ph->n_e, ph->n_ph, ph->n_e);
	return (1);
}

void	ft_print(t_phil *ph, int i)
{
	t_phil	*tmp;
	t_uli	tme;

	tmp = ph;
	tme = get_time() - ph->strt;
	while (tmp->nxt != ph)
	{
		if (tmp->dead)
			return ;
		tmp = tmp->nxt;
	}
	if (tmp->dead)
		return ;
	pthread_mutex_lock(ph->act);
	if (i == 1 && !ph->dead)// && ph->n_e)
		printf("%li\t%i is thinking\n", tme, ph->n_ph);
	else if (i == 2 && !ph->dead && ph->n_e)
		printf("%li\t%i has taken a fork\n", tme, ph->n_ph);
	else if (i == 3 && !ph->dead && ph->n_e--)
		printf("%li\t%i is eating\n", tme, ph->n_ph);
	else if (i == 4 && !ph->dead)// && ph->n_e)
		printf("%li\t%i is sleeping\n", tme, ph->n_ph);
	pthread_mutex_unlock(ph->act);
}

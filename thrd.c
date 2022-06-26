/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thrd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orandan <orandan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:33:04 by orandan           #+#    #+#             */
/*   Updated: 2022/06/26 11:16:12 by orandan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_phil	*ph;

	ph = (t_phil *)arg;
	while (get_time() - ph->strt < ph->t_l)
	{
        printf("%li\t%i is thinking \t\t(t_l = %li)\n", get_time() - ph->strt, ph->n_ph, ph->t_l);
		pthread_mutex_lock(&(ph->frk));
        printf("%li\t%i has taken a fork \t(t_l = %li)\n", get_time() - ph->strt, ph->n_ph, ph->t_l);
		pthread_mutex_lock(&((ph->nxt)->frk));
        printf("%li\t%i has taken a fork \t(t_l = %li)\n", get_time() - ph->strt, ph->n_ph, ph->t_l);
        printf("%li\t%i is eating \t\t(t_l = %li)\n", get_time() - ph->strt, ph->n_ph, ph->t_l);
		ph->t_l = get_time() - ph->strt + ph->t_d;
		ft_usleep(ph->t_e * 1000);
        printf("%li\t%i is sleeping \t\t(t_l = %li)\n", get_time() - ph->strt, ph->n_ph, ph->t_l);
		pthread_mutex_unlock(&((ph->nxt)->frk));
		pthread_mutex_unlock(&(ph->frk));
		ft_usleep(ph->t_s * 1000);
	}
	ph->dead = get_time() - ph->strt;
	return (NULL);
}

void    *die(void *arg)
{
	t_phil	*ph;
	t_phil	*tmp;

	ph = (t_phil *)arg;
	tmp = ph;
	while (get_time() - ph->strt < ph->t_l)
		ph = ph->nxt;
	ph->dead = get_time() - ph->strt;
	printf("%li	%i died\n", ph->dead, ph->n_ph);
//	pthrd_join(ph); how to kill all threads at this point
	return (NULL);
}

void	pthrd_create(t_phil *ph)
{
	pthread_t	die_thrd;
	t_phil	*tmp;

	tmp = ph;
	while (ph->nxt != tmp)
	{
    	ph->strt = get_time();
		pthread_create(&ph->thrd, NULL, &routine, ph);
		ph = ph->nxt;
	}
	ph->strt = get_time();
	pthread_create(&ph->thrd, NULL, &routine, ph);
	pthread_create(&die_thrd, NULL, &die, ph);
	pthread_join(die_thrd, NULL);
    pthrd_join(ph);
}

void	pthrd_join(t_phil *ph)
{
	t_phil	*tmp;
	
	tmp = ph;
	while (ph->nxt != tmp)
	{	
		pthread_join(ph->thrd, NULL);
		ph = ph->nxt;
	}
	pthread_join(ph->thrd, NULL);
}
